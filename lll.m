 
    figure;
    plot(estado_ideal(1, 1:35), estado_ideal(2, 1:35), 'b-')
    hold on;
    plot(estado_filtrado(1, 1:35), estado_filtrado(2, 1:35), 'r-')
    plot(estado_medido(1, 1:35), estado_medido(2, 1:35), 'g-')
    plot(estado_real(1, 1:150), estado_real(2, 1:150), 'm-')
    hold off;
    xlabel('X [mm]');
    ylabel('Y [mm]');
    legend('Estado medido', 'Estado filtrado', 'Estado ideal', 'Estado real');
    
    figure;
    plot(estado_ideal(1, 1:35), 'b-')
    hold on;
    plot(estado_filtrado(1, 1:35), 'r-')
    plot(estado_medido(1, 1:35), 'g-')
    plot(estado_real(1, 1:35), 'm-')
    hold off;
    xlabel('Tiempo [s]');
    ylabel('X [mm]');
    legend('Estado medido', 'Estado filtrado', 'Estado ideal', 'Estado real');
    
    figure;
    plot(estado_ideal(2, 1:35), 'b-')
    hold on;
    plot(estado_filtrado(2, 1:35), 'r-')
    plot(estado_medido(2, 1:35), 'g-')
    plot(estado_real(2, 1:35), 'm-')
    hold off;
    xlabel('Tiempo [s]');
    ylabel('Y [mm]');
    legend('Estado medido', 'Estado filtrado', 'Estado ideal', 'Estado real');
    
