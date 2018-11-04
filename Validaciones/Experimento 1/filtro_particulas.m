%% Funcion para implementar el filtro de particulas
function [estado_filtro, particulas, wk] = filtro_particulas(particula_old, wk, robot)

    vr = robot.vel(1);
    vl = robot.vel(2);
    
    Np = robot.Np;
    
    z = robot.meas;

	% Separacion de memoria
	x_k = zeros(3, Np);
    pdf_y_x = zeros(1, Np);
    dt = 0.10;

	% Estado anterior y asignacion de pesos pasados
    particulas = particula_old;
    w_k_1 = wk;
    
    for i = 1:Np
        x_k(:, i) = modelo_d(vl, vr, particulas(:, i), dt);
        pdf_y_x(i) = pdf_fun(z, x_k(:, i), robot);
    end
    
    wk = bsxfun(@times, w_k_1, pdf_y_x);
	wk = bsxfun(@rdivide, wk, sum(wk)); % Normalizacion de pesos
  
	Neff = 1/sum(wk.^2, 2); % Muestreado efectivo

	% Se toman la mitad de las particulas para veerificar
	% si hay degeneracion en el proceso
	Nt = 0.5*Np; 

	% Se verifica la defeneracion de particulas en el filtro
    if Neff < Nt
        [x_k, wk] = remuestreo(x_k, wk);
    end

    pre_estado = bsxfun(@times, x_k, wk);
    estado_filtro = sum(pre_estado, 2);
       
    particulas = x_k;    
end


%% Funcion para obtener la PDF de p(y_k|x_k)
function p_y_x = pdf_fun(z, estado, robot)
	sigma_m  = diag([76.1919 76.1919 76.1919]);
    
    robot_i = robot;
    robot_i.estado = estado;
    
	z_m = ultrasonido(robot_i, 0);
    
    error = (z - z_m);  
    
    lamnda = 1/sqrt(det(sigma_m)*(2*pi)^(3));
    p_y_x = lamnda*exp(-0.5*(error'/sigma_m)*error);
end


function [x_h, w_h] = remuestreo(xk, wk)
%     Ns = length(wk);
% 
%     limite  = min([0 cumsum(wk)], 1);
%     limite(end) = 1;
% 
%     rand_num = rand/Ns;
% 
%     [~, index] = histc(rand_num:1/Ns:1, limite);
%  
%     x_h = xk(:, index);
%     w_h = repmat(1/Ns, 1, Ns);

    Np = length(wk);   
    W = cumsum(wk);

    index = zeros(1, Np);
    j = 1; i = 1;
    
    while j <= Np
       ruleta = rand(3, 1);
       
       if all(ruleta <= W(i))
            index(j) = i;
            j = j + 1;
       end 
       
       i =  round(Np*rand + 1);
       
       if i > Np
           i = Np;
       end
       
    end
    x_h = xk(:, index);
    w_h = repmat(1/Np, 1, Np);
end

function estado_new = modelo_d(vl, vr, estado, dt)
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