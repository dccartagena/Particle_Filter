function ejemplo()
    clear all; clc;

    %Ejemplo de como usar la funcion cinem_directa

    t0 = 0;
    tf = 20;

    [mapa_ruta, camino, robot] = gen_ruta();
    index = find(camino(:, 1) == 0);
    camino(index, :) = [];
    camino = flipud(camino);

    steps = size(camino, 1)*3;

    dt = (tf - t0) / steps;

    figure;

    %mapa;
    hold on;
    for i = 1:steps

        %if (i < steps*3) && ((mod(i, 3) == 0) || i == 1)
        %    chi_target = camino(k + 1, :) ;
        %    k = k + 1;
        %elseif (i == steps*3)
        %    chi_target = camino(end, :);
        %end

        %if i == 1
        %    estado = [camino(1, :) 0];
        %end

        %chi_control = control_robot(estado, chi_target);

        %vr_0 = vr;
        %vl_0 = vl;

        % [vl, vr] = modelo_inverso(chi_control, estado);
        [vl, vr] = cinem_inv(estado, chi_target, dt);

        %if mod(i, 3) == 0
        %    t_x = i;
        %    
        %    vr_0 = vr_f;
       %     vr_f = vr;
       %     
       %     vl_0 = vl_f;
      %      vl_f = vl;
      %      
      %      a_0 = a_x;
      %  elseif i == 1
     %       
      %      vl_f = vl;
       %     vr_f = vr;
      %      a_0 = a_x;
       %     
      %  end

        % t = abs(i - t_x);

    %    [vr, a_x] = pol_vel(vr_0, vr_f, a_0, t, dt); 
    %    [vl, a_x] = pol_vel(vl_0, vl_f, a_0, t, dt);

        %estado = modelo_directo(vl, vr, estado, dt); 
        estado = cinem_directa(vl, vr, estado, dt);

        %imagesc(mapa_ruta);
        %plot_sim(estado);
        pause(0.01);

        if i~=steps
            clf;
        end
    end
    hold off;
end


function [vl, vr, u] = modelo_inv(d_estado, estado)
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

function [d_estado] = modelo_control(estado_target, estado)
    error = abs(estado_target - estado([1 2]))./estado([1 2]);
    if (error(1) < 0.07) && (error(2) < 0.07)
        d_estado = [0 0 0]';
    else
        v = 1;
        theta = estado(3);
        K = 0.1;

        L = sqrt((estado_target(1) - estado(1))^2 + (estado_target(2) - estado(2))^2);
        delta = (estado_target(1) - estado(1))*cos(theta) + (estado_target(2) - estado(2))*sin(theta);

        gamma = -(2*delta)/(K*L^2);

        d_x = -v*sin(theta);
        d_y =  v*cos(theta);
        d_theta = v*gamma;

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


