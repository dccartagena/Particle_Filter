function ejemplo_2()
    
    close all;

    tipo = 5;
    
    [mapa, ~, camino, ~] = gen_ruta(tipo);
    
    puntos = size(camino, 1);
    
    % Cantidad de puntos en el mapa
    [punto_Y, punto_X] = size(mapa);
    
    % Mapa a recorrer
    X_map = linspace(0, 4060, punto_X);
    Y_map = linspace(0, 5175, punto_Y);
    
    gamma = 0;
    
    % Tiempo de simulacion entre puntos
    steps = 5; % Para que funcione la simulacion bien, poner steps = 3
    
    % Diferencial de tiempo
    dt = 0.1;
    
    tiempo = steps*(puntos-1);
    
    vl = zeros(1, steps*(puntos-1));
    vr = zeros(1, steps*(puntos-1));
    
    d_estado = zeros(3, steps*(puntos-1));

    estado = zeros(3, steps*(puntos-1));
    
    estado_target = zeros(steps*(puntos-1), 2);
    
    k = 1;
    
    for i = 2:puntos
        X_target = linspace(X_map(camino(i - 1, 1)), X_map(camino(i, 1)), steps);
        Y_target = linspace(Y_map(camino(i - 1, 2)), Y_map(camino(i, 2)), steps);
        estado_target(k:(k + steps - 1), :) = [X_target' Y_target'];
        k = k + steps;
    end
    
    % Estado inicial
    X_init = estado_target(1, 1);
    Y_init = estado_target(1, 2);
    estado_inicial = [X_init Y_init 0]';
    
    estado(:, 1) = estado_inicial;
    
    Np = 500;
    
    w_k = repmat(1/Np, 1, Np);
    estado_filtrado = zeros(3, steps*(puntos-1));
    particulas = mvnrnd(estado_inicial,diag([100 100 0.5]), Np)';
    
    estado_filtrado(:, 1) = estado_inicial;
    
    robot.mapa = mapa;
    robot.X_map = X_map;
    robot.Y_map = Y_map;
    robot.Np = Np;
    
    figure;
    hold on;
    
    for i = 2:1:steps*(puntos-1)
        
        [d_estado(:, i), ~] = modelo_control(estado_target(i, :), estado(:, i - 1), tiempo, i, gamma);

        [vl(i), vr(i)] = modelo_inv(d_estado(:, i), estado(:, i - 1));

        ruido_vel = gen_ruido_vel();
        
        vl(i) = vl(i) + ruido_vel(1);
        vr(i) = vr(i) + ruido_vel(1);

        estado(:, i) = modelo_directo(vl(i), vr(i), estado(:, i - 1), dt);            
        
        robot.estado = estado(:, i);
        robot.vel = [vr(i) vl(i)];
        
         z = ultrasonido(robot, 1);
         robot.meas = z;
        
        [estado_filtrado(:, i), particulas, w_k] = filtro_particulas(particulas, w_k, robot);
 
        plot_rob(estado(:, i));
        plot(estado(1, 1:i), estado(2, 1:i), 'b-')
        particulas_view(particulas);
        xlabel('X [mm]');
        ylabel('Y [mm]');
        title('Mapa');
        xlim([0 4060]);
        ylim([0 5175]);

        pause(1e-6);
        
        if i < steps*(puntos-1)
            clf;
        end
    end
    
    figure;
    plot(estado(1, 1:i), estado(2, 1:i), 'b-')
    hold on;
    plot(estado_filtrado(1, :), estado_filtrado(2, :), 'r-')
    hold off;
    xlabel('X [mm]');
    ylabel('Y [mm]');
    legend('Estado real', 'Estado estimado');
    
    figure;
    plot(estado_filtrado(3, :), 'r-'); hold on;
    plot(estado(3, :), 'b-'); hold off;
    xlabel('tiempo [s]');
    ylabel('angulo [rad]');
    legend('Estado real', 'Estado estimado');
    
    figure;
    plot(estado_filtrado(1, :), 'r-'); hold on;
    plot(estado(1, :), 'b-'); hold off;
    xlabel('tiempo [s]');
    ylabel('X [mm]');
    legend('Estado real', 'Estado estimado');
    
    figure;
    plot(estado_filtrado(2, :), 'r-'); hold on;
    plot(estado(2, :), 'b-'); hold off;
    xlabel('tiempo [s]');
    ylabel('Y [mm]');
    legend('Estado real', 'Estado estimado');
end

%% Funcion para calcular el modelo jacobiano inverso
function [vl, vr] = modelo_inv(d_estado, estado)
    % Distancia entre llantas
    l = 252.5; 
    
    % Angulo anterior
    theta = estado(3);
    
    % Jacobiano inverso
    J_inv = [-sin(theta) cos(theta) 0;
              0          0          1];
    
    % Velocidades lineal y angular      
    u = J_inv*d_estado;
    
    v = u(1);
    w = u(2);
    
    % Velocidades de llantas
    vl = v - (l/2)*w;   
    vr = v + (l/2)*w; 
    
    v_max = max(abs(vl), abs(vr));
    
    if v_max >= 450
        vr = (vr/v_max)*450;
        vl = (vl/v_max)*450;
    end
    
end

%% Funcion de control en la simulacion
function [d_estado, gamma] = modelo_control(estado_target, estado, gamma, tiempo, t, dt)

        v = 200;
        %v = pol_vel(tiempo, t);
        
        theta = estado(3);
        
        Kp = 10;
        Kd = 0;
        Ki = 0;
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
end

%% Funcion para generar el polinomio en las velocidades
function V = pol_vel(tiempo, t)
    
    t0 = 1;

%     if t <= round(steps*0.75)
%         t_aux = 1;
        tf = tiempo;
        
        v_0 = 25;
        v_f = 100;
        
        a_0 = 40;
        a_f = 40;
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
end

%% Funcion de ruido en velocidades
function ruido = gen_ruido_vel()
    std_vel = 1;
    ruido = normrnd(0, std_vel, 1, 2);
end

function [vl, vr] = control_new(target, estado)

    v_ref = 100;
    w_ref = deg2rad(10);
    
    error = target - estado([1 2])';
    error(3) = 0;
    
    delta = 13;
    beta = 0.9;
    
    k1 = 2*delta*sqrt(w_ref^2 + beta*v_ref^2);
    k2 = beta*abs(v_ref);
    k3 = 2*delta*sqrt(w_ref^2 + beta*v_ref^2);
    
    vr = -k1*error(1);
    vl = -k2*sign(v_ref)*error(2) - k3*error(3);

end




