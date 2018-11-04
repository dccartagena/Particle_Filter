function estado_new = modelo_directo(vl, vr, estado, dt)
    % Distancia entre llantas
    l = 252.5; 
    
    % Velocidades lineal y angular
    v = (vr + vl)/2;
    w = (vr - vl)/l;
    
    % Estado anterior
    x_last = estado(1);
    y_last = estado(2);
    theta_last = estado(3);
    
    % Calculo del modelo jacobiano
    u = [v w]';
    
    % Jacobiano
    J = [-sin(theta_last) 0;
          cos(theta_last) 0;
          0               1];
    % Vector de velocidades cartesianas  
    d_estado = J*u;
    
    std_rot = 0.0131;
    ruido_rot = normrnd(0, std_rot);
    
    std_trans = 1.6358;
    ruido_trans = normrnd(0, std_trans);
    
    x = x_last + d_estado(1)*dt + ruido_trans*sin(theta_last);
    y = y_last + d_estado(2)*dt + ruido_trans*cos(theta_last);
    theta = get_ang(theta_last + get_ang(d_estado(3)*dt + ruido_rot));
    
    estado_new = [x y theta]';
end

