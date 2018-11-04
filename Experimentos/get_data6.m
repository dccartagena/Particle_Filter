%% Toma datos de distancia
dist1 = abs(xlsread('Experimento_6.xlsx','Prueba 1','B3:B15')); dist1 = [0; dist1];
dist2 = abs(xlsread('Experimento_6.xlsx','Prueba 2','B3:B13')); dist2 = [0; dist2];
dist3 = abs(xlsread('Experimento_6.xlsx','Prueba 3','B3:B14')); dist3 = [0; dist3];
dist4 = abs(xlsread('Experimento_6.xlsx','Prueba 4','B3:B13')); dist4 = [0; dist4];
dist5 = abs(xlsread('Experimento_6.xlsx','Prueba 5','B3:B14')); dist5 = [0; dist5];
dist6 = abs(xlsread('Experimento_6.xlsx','Prueba 6','B3:B14')); dist6 = [0; dist6];
dist7 = abs(xlsread('Experimento_6.xlsx','Prueba 7','B3:B14')); dist7 = [0; dist7];
dist8 = abs(xlsread('Experimento_6.xlsx','Prueba 8','B3:B14')); dist8 = [0; dist8];
dist9 = abs(xlsread('Experimento_6.xlsx','Prueba 9','B3:B14')); dist9 = [0; dist9];
dist10 = abs(xlsread('Experimento_6.xlsx','Prueba 10','B3:B14')); dist10 = [0; dist10];

%% Toma datos de angulo
ang1 = xlsread('Experimento_6.xlsx','Prueba 1','C3:C15'); ang1 = [0; ang1];
ang2 = xlsread('Experimento_6.xlsx','Prueba 2','C3:C13'); ang2 = [0; ang2];
ang3 = xlsread('Experimento_6.xlsx','Prueba 3','C3:C14'); ang3 = [0; ang3];
ang4 = xlsread('Experimento_6.xlsx','Prueba 4','C3:C13'); ang4 = [0; ang4];
ang5 = xlsread('Experimento_6.xlsx','Prueba 5','C3:C14'); ang5 = [0; ang5]; 
ang6 = xlsread('Experimento_6.xlsx','Prueba 6','C3:C14'); ang6 = [0; ang6];
ang7 = xlsread('Experimento_6.xlsx','Prueba 7','C3:C14'); ang7 = [0; ang7];
ang8 = xlsread('Experimento_6.xlsx','Prueba 8','C3:C14'); ang8 = [0; ang8];
ang9 = xlsread('Experimento_6.xlsx','Prueba 9','C3:C14'); ang9 = [0; ang9];
ang10 = xlsread('Experimento_6.xlsx','Prueba 10','C3:C14'); ang10 = [0; ang10];

%% Toma datos de tiempo
tiempo1 = xlsread('Experimento_6.xlsx','Prueba 1','A3:A15'); tiempo1 = [0; tiempo1];
tiempo2 = xlsread('Experimento_6.xlsx','Prueba 2','A3:A13'); tiempo2 = [0; tiempo2];
tiempo3 = xlsread('Experimento_6.xlsx','Prueba 3','A3:A14'); tiempo3 = [0; tiempo3];
tiempo4 = xlsread('Experimento_6.xlsx','Prueba 4','A3:A13'); tiempo4 = [0; tiempo4];
tiempo5 = xlsread('Experimento_6.xlsx','Prueba 5','A3:A14'); tiempo5 = [0; tiempo5];
tiempo6 = xlsread('Experimento_6.xlsx','Prueba 6','A3:A14'); tiempo6 = [0; tiempo6];
tiempo7 = xlsread('Experimento_6.xlsx','Prueba 7','A3:A14'); tiempo7 = [0; tiempo7];
tiempo8 = xlsread('Experimento_6.xlsx','Prueba 8','A3:A14'); tiempo8 = [0; tiempo8];
tiempo9 = xlsread('Experimento_6.xlsx','Prueba 9','A3:A14'); tiempo9 = [0; tiempo9];
tiempo10 = xlsread('Experimento_6.xlsx','Prueba 10','A3:A14'); tiempo10 = [0; tiempo10];

%% Plot de distancia vs. tiempo
figure;
grid on;
hold on;
plot(tiempo1, dist1);
plot(tiempo2, dist2);
plot(tiempo3, dist3);
plot(tiempo4, dist4);
plot(tiempo5, dist5);
plot(tiempo6, dist6);
plot(tiempo7, dist7);
plot(tiempo8, dist8);
plot(tiempo9, dist9);
plot(tiempo10, dist10);
hold off;

title('Experimento 6');
legend('Prueba 1','Prueba 2', 'Prueba 3', 'Prueba 4', 'Prueba 5', 'Prueba 6',...
    'Prueba 7', 'Prueba 8', 'Prueba 9', 'Prueba 10', 'Location', 'southeast');
xlabel('Tiempo [s]');
ylabel('Distancia [mm]');

%% Plot de angulo vs. tiempo
figure;
grid on;
hold on;
plot(tiempo1, ang1);
plot(tiempo2, ang2);
plot(tiempo3, ang3);
plot(tiempo4, ang4);
plot(tiempo5, ang5);
plot(tiempo6, ang6);
plot(tiempo7, ang7);
plot(tiempo8, ang8);
plot(tiempo9, ang9);
plot(tiempo10, ang10);
hold off;

title('Experimento 6');
leg = legend('Prueba 1','Prueba 2', 'Prueba 3', 'Prueba 4', 'Prueba 5', 'Prueba 6',...
    'Prueba 7', 'Prueba 8', 'Prueba 9', 'Prueba 10', 'Location', 'southeast');
xlabel('Tiempo [s]');
ylabel('Angulo [º]');