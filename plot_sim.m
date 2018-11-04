function plot_sim(estado)
    %ancho = 70;
    %largo = 35;
    
    ancho = 200;
    largo = 200;
    %Dibujo del robot
    hold on;
    plot(estado(1), estado(2), '*'); 
    plot_rob(estado);
    %plot(ICC(1), ICC(2), '*');
    %axis([0 ancho 0 largo]);
    axis([-ancho ancho -largo largo]);
    box on; title('grafica movimiento robot'); xlabel('x'); ylabel('y');
    
end

function plot_rob(estado)
    R = 1;
    r = R/2;
    
    x = estado(1);
    y = estado(2);
    theta = estado(3);
    
    hold on;
    p = 0:pi/20:2*pi;
    x_u = R*cos(p) + x;
    y_u = R*sin(p) + y;
    rob_u = plot(x_u, y_u, 'r');
   
    x_i = x + r*cos(theta);
    y_i = y + r*sin(theta);
    rob_i = plot(x_i, y_i, 'O');
    
end

