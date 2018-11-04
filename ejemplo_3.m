function ejemplo_3()
    gamma = 0;

    steps = 70; %size(camino, 1);
    dt = 0.1;
    
    estado_target = zeros(steps*(puntos-1), 2);
    
    k = 1;
    
    for i = 2:puntos
        X_target = linspace(X_map(camino(i - 1, 1)), X_map(camino(i, 1)), steps);
        Y_target = linspace(Y_map(camino(i - 1, 2)), Y_map(camino(i, 2)), steps);
        estado_target(k:(k + steps - 1), :) = [X_target' Y_target'];
        k = k + steps;
    end
    
%     estado_target = [50 50]';
    
    vl = zeros(1, steps);
    vr = zeros(1, steps);
    
    d_estado = zeros(3, steps);

    estado = zeros(3, steps);
    t = 0;

    figure;
    hold on;
    
    for i=2:steps

        [d_estado(:, i), gamma] = modelo_control(estado_target, estado(:, i - 1), gamma, dt);
        [vl(i), vr(i)] = modelo_inv(d_estado(:, i), estado(:, i - 1));
 
        t = t + 1;
        
        v_max = max(vr(i), vl(i));
        if v_max >=450
            vr(i) = (vr(i)/v_max)*450;
            vl(i) = (vl(i)/v_max)*450;
        end
        
        estado(:, i) = modelo_dir(vl(i), vr(i), estado(:, i - 1), dt);            

        plot_rob(estado(:, i));
        pause(0.05);
    end
    hold off;
end


function [vl, vr] = modelo_inv(d_estado, estado)
    l = 252.5;
    
    theta = estado(3);
    
    J_inv = [-sin(theta) cos(theta) 0;
              0          0          1];
          
    u = J_inv*d_estado;
    
    v = u(1);
    w = u(2);
    
    vl = v - (l/2)*w;
    vr = v + (l/2)*w;
    
end

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
    
end

function [d_estado, gamma] = modelo_control(estado_target, estado, gamma, dt)
    error = abs(estado_target - estado([1 2]))./estado([1 2]);
    %t = 0;
    if (error(1) < 0.1) && (error(2) < 0.1)
        d_estado = [0 0 0]';
        %t = 1;
    else
        v = 100;
        theta = estado(3);
        Kp = 2;
        Kd = 0;
        Ki = 0;
        %tao = 100;

        L = sqrt((estado_target(1) - estado(1))^2 + (estado_target(2) - estado(2))^2);
        delta = (estado_target(1) - estado(1))*cos(theta) + (estado_target(2) - estado(2))*sin(theta);
        
        last_gamma = gamma;
        gamma = -(2*delta)/(L^2);
        
        gamma_hat = Kp*gamma + Kd*(gamma - last_gamma)/dt + Ki*(gamma + last_gamma)*dt/2;
        %gamma_hat = (-gamma + K)/tao;
        
        d_x = -v*sin(theta);
        d_y =  v*cos(theta);
        d_theta = v*gamma_hat;

        d_estado = [d_x d_y d_theta]';
    end
end

function theta = get_ang(x)
    if x > pi
        theta = x - 2*pi;
    elseif x < -pi
        theta = x + 2*pi;
    else
        theta = x;
    end
end





