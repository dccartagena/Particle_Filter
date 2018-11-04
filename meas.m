%% Funcion para simular las medidas del robot
function Z = meas(estado_old, estado, data) %(estado, estado_old, data)
    dx = estado(1) - estado_old(1);
    dy = estado(2) - estado_old(2);
    
    if data == 1
        ruido = ruido_obs();
    else
        ruido = [0 0];
    end
    
    ro = sqrt(dx^2 + dy^2 + ruido(1)^2);
        
    theta = get_ang(get_ang(atan2(-dx, dy)) - estado_old(3)) + ruido(2);
    
%     x = estado_old(1) - ro*cos(theta);
%     y = estado_old(2) + ro*sin(theta);
    
%     L = sqrt((estado_old(1) - estado(1))^2 + (estado_old(2) - estado(2))^2);
%     delta = (estado(1) - estado_old(1))*cos(theta) + (estado(2) - estado_old(2))*sin(theta);
%         
%     gamma = delta/L;
     
%     phi = get_ang(atan2(-dy, -dx) + ruido(3));
    
    Z = [ro theta];
end

%% Funcion para generar ruido en las mediciones
function ruido = ruido_obs()
	% Para el error en la toma de medidas de las velocidades,
	% se asume una probabilidad normal con las siguientes
	% especificaciones:
	mu_obs = [0 0]; % Media del error en medicion de velocidades
	sigma_obs  = diag(sqrt([5e-3 5e-5])); % Desviacion estandar del error en medicion de velocidades

	ruido = mvnrnd(mu_obs, sigma_obs); % Ruido en la medicion de posicion
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