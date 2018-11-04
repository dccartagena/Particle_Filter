function simulacion_ruta(handles)

    puntos = size(handles.camino, 1);
    
    [punto_Y, punto_X]  = size(handles.mapa_ruta);
    
    X_map = linspace(0, 500, punto_X);
    Y_map = linspace(0, 500, punto_Y);
    
    gamma = 0;

    steps = 150; %size(camino, 1);
    dt = 0.1;
    
    tiempo = steps;
    
    X_init = X_map(handles.camino(1, 1));
    Y_init = Y_map(handles.camino(1, 2));
    
    estado_inicial = [X_init Y_init pi/2]';
    
    vl = zeros(1, steps*puntos);
    vr = zeros(1, steps*puntos);
    
    d_estado = zeros(3, steps*puntos);

    estado = zeros(3, steps*puntos);
    estado(:, 1) = estado_inicial;
    
    for i = 2:puntos
        X_target = linspace(X_map(handles.camino(i - 1, 1)), X_map(handles.camino(i, 1)), steps);
        Y_target = linspace(Y_map(handles.camino(i - 1, 2)), Y_map(handles.camino(i, 2)), steps);
        estado_target = [X_target' Y_target'];
    end
    
    %figure;
    hold on;
    
    for i=2:steps
        string_pos = strcat(num2str(estado(1, i - 1), 3), ',', num2str(estado(2, i - 1), 3));
        set(handles.edit8, 'String', string_pos);

        [d_estado(:, i), L] = modelo_control(estado_target(i, :), estado(:, i - 1), gamma,  tiempo, i, handles);

        [vl(i), vr(i)] = modelo_inv(d_estado(:, i), estado(:, i - 1));
        
        v_max = max(abs(vr(i)), abs(vl(i)));
        
        if v_max >=450
            vr(i) = (vr(i)/v_max)*450;
            vl(i) = (vl(i)/v_max)*450;
        end
        
        diff_vel_r = abs(vr(i) - vr(i - 1)); sign_vr = sign(vr(i));
        diff_vel_l = abs(vl(i) - vl(i - 1)); sign_vl = sign(vl(i));
        
        if (diff_vel_r >= 50) && (diff_vel_l >= 50)
            vr(i) = vr(i - 1) + sign_vr*50;
            vl(i) = vl(i - 1) + sign_vl*50;
        elseif (diff_vel_r >= 50)
            vr(i) = vr(i - 1) + sign_vr*(diff_vel_r/diff_vel_r)*50;
            vl(i) = vl(i - 1) + sign_vl*(diff_vel_l/diff_vel_r)*50;
        elseif (diff_vel_l >= 50)
            vr(i) = vr(i - 1) + sign_vr*(diff_vel_r/diff_vel_l)*50;
            vl(i) = vl(i - 1) + sign_vl*(diff_vel_l/diff_vel_l)*50;
        end

        std_vel = str2double(get(handles.edit2, 'String'));
        ruido_l = gen_ruido_vel(std_vel);
        ruido_r = gen_ruido_vel(std_vel);

        vl(i) = vl(i) + ruido_l;
        vr(i) = vr(i) + ruido_r;

        estado(:, i) = modelo_dir(vl(i), vr(i), estado(:, i - 1), dt);            

        std_sys = str2double(get(handles.edit1, 'String'));
        ruido_sys = gen_ruido_sys(std_sys);      

        estado(:, i) = estado(:, i) + ruido_sys;

        axes(handles.axes1);
        plot_rob(estado(:, i));
        plot(estado(1, 1:i), estado(2, 1:i), '-')
        xlabel('X [mm]');
        ylabel('Y [mm]');
        title('Mapa');
        xlim([0 500]);
        ylim([0 500])

        axes(handles.axes4);
        plot(1:i, vr(1:i));
        ylabel('velocidad [mm/s]');
        xlabel('Tiempo [s]');
        title('Velocidad llanta derecha');
        %xlim([0 500]);
        ylim([-510 510]);

        axes(handles.axes5);
        plot(1:i, vl(1:i));
        ylabel('velocidad [mm/s]');
        xlabel('Tiempo [s]');
        title('Velocidad llanta izquierda');
        %xlim([0 500]);
        ylim([-510 510]);

        pause(0.02);
        
%         if L <= 0.2
%             break;
%         end

        if i < steps
            cla(handles.axes1)
        end
    end
    
    hold off;



function [vl, vr] = modelo_inv(d_estado, estado)
    l = 252.5;
    
    theta = estado(3);
    
    J_inv = [-sin(theta) cos(theta) 0;
              0          0          1];
    
    u = J_inv*d_estado/10;
    
    v = u(1);
    w = u(2);
    
    vl = (v - (l/2)*w);
    vr = (v + (l/2)*w);
    


function [estado] = modelo_dir(vl, vr, estado, dt)
    l = 252.5;
    
    v = (vr + vl)/2;
    w = (vr - vl)/l;
    
    x_last = estado(1);
    y_last = estado(2);
    theta_last = estado(3);
    
    % Calculo del modelo jacobiano
    u = [v w]';

    J = [-sin(theta_last) 0;
          cos(theta_last) 0;
          0               1];
      
    d_estado = J*u;
    
    x = x_last + d_estado(1)*dt;
    y = y_last + d_estado(2)*dt;
    theta = get_ang(theta_last + get_ang(d_estado(3)*dt));
    
    estado = [x y theta]';

function [d_estado, L] = modelo_control(estado_target, estado, gamma, tiempo, k, handles)
    
%     v = str2double(get(handles.edit4, 'String')); 
    v = pol_vel(tiempo, k, handles); 

    theta = estado(3);
    Kp = 10;
    %Kd = 0;
    %Ki = 0;
    %tao = 100;

    L = sqrt((estado_target(1) - estado(1))^2 + (estado_target(2) - estado(2))^2);
    delta = (estado_target(1) - estado(1))*cos(theta) + (estado_target(2) - estado(2))*sin(theta);

    last_gamma = gamma;
    gamma = -(2*delta)/(L^2);

    gamma_hat = Kp*gamma; % + Kd*(gamma - last_gamma)/dt + Ki*(gamma + last_gamma)*dt/2;
    %gamma_hat = (-gamma + K)/tao;

    d_x = -v*sin(theta);
    d_y =  v*cos(theta);
    d_theta = v*gamma_hat;

    d_estado = [d_x d_y d_theta]';


function theta = get_ang(x)
    if x > pi
        theta = x - 2*pi;
    elseif x < -pi
        theta = x + 2*pi;
    else
        theta = x;
    end

function V = pol_vel(tiempo, t, handles)
    
    t0 = 0;
    tf = round(tiempo);
    
    v_f = str2double(get(handles.edit4, 'String'));
    a_f = str2double(get(handles.edit5, 'String'));
    
    
%     if t <= round(steps*0.75)
%         t_aux = 1;
%         tf = round(steps*.75);
        
        v_0 = 0;
%         v_f = 75;
        
        a_0 = 40;
%         a_f = 40;
%         
%     else
%         t_aux = round(steps*0.75);
%         tf = round(steps*0.25);
%         
%         v_0 = 200;
%         v_f = 0;
%         
%         a_0 = -40;
%         a_f = -40;
%     end
%     t = t - t_aux;
    
%     % Parametros de polinomio de 3º orden
%     C = [t0^3   t0^2 t0 1;
%          tf^3   tf^2 tf 1;
%          3*t0^2 2*t0 1  0;
%          3*tf^2 2*tf 1  0];
%      
%      X = [v_0 v_f a_0 a_f]';

    % Parametros de polinomio de 1º orden
    C = [t0 1;
         tf 1];
     X = [v_0 v_f]';

     A = C\X;

     V = A(1)*t + A(2);
%      V = A(1)*t^3 + A(2)*t^2 + A(3)*t + A(4); 

function ruido = gen_ruido_vel(std_vel)
    ruido = normrnd(0, std_vel);

function ruido_sys = gen_ruido_sys(std_sys)
    ruido_X = normrnd(0, std_sys);
    ruido_Y = normrnd(0, std_sys);
    ruido_theta = normrnd(0, std_sys/100);
    
    ruido_sys = [ruido_X ruido_Y ruido_theta]';
