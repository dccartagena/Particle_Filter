%%------- Algoritmo de localización por filtro de partículas ---------
% Por: Juan Diego Cardenas
% Institucion: Universidad EIA
% Contacto: dccartagena@gmail.com
%---------------------------------------------------------------------
%% Mediante este programa se simulara el movimiento de un robot movil
% y se estimara su estado (X, Y, theta) mediante la implementacion de 
% un filtro de particulas.

clear, clc, close all;

%% Generacion de rutas
[mapa_ruta, camino, robot] = gen_ruta();

medida = [100 200]; % Medidas reales del mapa

[fila, columna] = size(mapa_ruta);

mapa_loc.X = linspace(0, medida(1), columna);
mapa_loc.Y = linspace(0, medida(2), fila);

%% ----------------Para simulacion
% Parametros de simulacion
N = 1000; % Numero de simulaciones
t0 = 0; % Tiempo inicial
tf = 20; % Tiempo final
dt = (tf - t0)/N; % Diferencial de tiempo

% Separacion de espacio en memoria
vl = zeros(1, N); % Velocidad de llanta izquierda
vr = zeros(1, N); % Velocidad de llanta derecha

chi = zeros(3, N); % Estados: X, Y, theta
chi(1) = mapa_loc.X(robot(1)); chi(2) = mapa_loc.X(robot(2));
Z = zeros(3, N); % Observaciones: phi, theta

u = zeros(3, N); % Ruido del sistema
v = zeros(2, N); % Ruido de observaciones

%% ----------------Para el filtro de particulas
% Parametros del filtro
Np = 200; % Numero de particula

% Separacion de espacio de memoria
w_k = zeros(1, Np); % Vector de pesos
w_k_1 = zeros(1, Np); % Vector de pesos de ultima iteracion
particula = zeros(3, Np, N); % Matriz de particulas

chi_h = zeros(3, N); % Estados: X, Y, theta
Z_h = zeros(3, N); % Observaciones: phi, theta
vl_h = zeros(1, N); % Velocidad de llanta izquierda
vr_h = zeros(1, N); % Velocidad de llanta derecha

%% inicializacion de la simulacion
chi_0 = [0 0 0]'; % Estado inicial del sistema

% Simulacion del movimiento del robot
for k = 1:N
	if k == 1
		chi(:, k) = chi_0; % Inicializacion del primer estado
	else
		chi(:, k) = sistema(chi(:, k - 1), Z(:, k - 1));
	end

	[vl(k), vr(k)] = gen_vel();
	Z(:, 1) =  meas(estado, vr(k), vl(k), dt, 1);
end

% Implementacion del filtro del particulas
for k= 2:N

	if k == 1
		chi_h(:, k) = normrnd(0, 10, 3, 1); % Inicializacion del primer estado
	else
		[chi_h(:, k), particulas(:, :, k)] = filtro_particulas(chi_h(:, k - 1), Z_h(:, k - 1), dt);
	end

	[vl_h(k), vr_h(k)] = gen_vel();
	Z_h(:, k) = meas(chi_h(:, k), vr(k), vl(k), dt, 0);
end








