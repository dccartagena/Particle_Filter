function plot_rob(estado)
    R = 1;
    r = R/2;
    
    x = estado(1);
    y = estado(2);
    theta = estado(3) + pi/2;
    
    hold on;
    plot(x, y, '*');
    
    p = 0:pi/20:2*pi;
    x_u = R*cos(p) + x;
    y_u = R*sin(p) + y;
    plot(x_u, y_u, 'r');
   
    x_i = x + r*cos(theta);
    y_i = y + r*sin(theta);
    plot(x_i, y_i, 'O');
    
end