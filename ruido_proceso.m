function [ruido_tr, ruido_rot] = ruido_proceso()
	% Para el error en la medicion de las posiciones,
	% se asume una probabilidad normal con las siguientes
	% especificaciones:
	mu_pos = 0; % Media del error en posicion
	sigma_tr  = 10; % Desviacion estandar del error en posicion
	sigma_rot = 15; % Desviacion estandar del error en  angulo

	ruido_tr  = normrnd(mu_pos, sigma_tr, 2, 1); % Ruido en la medicion de posicion
	ruido_rot = normrnd(mu_pos, sigma_rot); % Ruido en la medicion de rotacion
end