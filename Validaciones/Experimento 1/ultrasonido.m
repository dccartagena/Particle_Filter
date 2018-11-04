function medida = ultrasonido(robot, dato)

    estado = robot.estado;
    mapa = robot.mapa;
    X_map = robot.X_map;
    Y_map = robot.Y_map;
    
    obst_map = find_obst(mapa);
    
    X_obst = X_map(obst_map(:, 1));
    Y_obst = Y_map(obst_map(:, 2));
    obst_list = [X_obst' Y_obst'];
    
    obst = get_obst(obst_list, estado);

    if dato == 1
        %std_sensor = 76.1919;
        std_sensor = 0;
        ruido = normrnd(0, std_sensor, 3, 1);
        
        plot_sensor(estado, obst)

    else
        ruido = zeros(3, 1);
    end
    
    medida = obst.estado(:, 1) + ruido;
    
    medida(medida>1500) = 1500;
end

function plot_sensor(estado, obst)
        hold on;
        sensor1X = [estado(1) obst.pos(1, 1)];
        sensor1Y = [estado(2) obst.pos(1, 2)];
        plot(sensor1X, sensor1Y, 'r');

        sensor2X = [estado(1) obst.pos(2, 1)];
        sensor2Y = [estado(2) obst.pos(2, 2)];
        plot(sensor2X, sensor2Y, 'g');

        sensor3X = [estado(1) obst.pos(3, 1)];
        sensor3Y = [estado(2) obst.pos(3, 2)];
        plot(sensor3X, sensor3Y, 'b');
        hold off;
end

function obst_list = find_obst(mapa)
    
    [u, v] = find(mapa == 1);
    obst_list = [v u];
    
end

function obst = get_obst(obst_list, estado)

    dim_obs = size(obst_list, 1);
    
    obst_estado = zeros(dim_obs, 2);
    last_error = inf(3, 1);
    
    error = zeros(3, 1);
    dist_min = inf(3, 1);
    
    obst_rob = zeros(3, 2);
    obst_pos = zeros(3, 2);
    
    theta = get_ang(estado(3) - pi/2);
    
    sensor1_ang = theta;
    sensor2_ang = get_ang(theta + 3*pi/2 + pi/4);
    sensor3_ang = get_ang(theta + pi/4);
    
    for i = 1:dim_obs
        dist = sqrt((obst_list(i, 1) - estado(1))^2 + ...
                    (obst_list(i, 2) - estado(2))^2);
                
        ang = get_ang(atan2(estado(2) - (obst_list(i, 2)), estado(1) - (obst_list(i, 1))));
        obst_estado(i, :) = [dist ang];
        
        error(1) = abs(abs(sensor1_ang) - abs(obst_estado(i, 2)));

        if (error(1) < last_error(1)) &&  ...
           (sign(sensor1_ang) == sign(obst_estado(i, 2)) ||...
           (sign(obst_estado(i, 2)) == 0))

            obst_rob(1, :) = obst_estado(i, :);
            obst_pos(1, :) = obst_list(i, :);

            last_error(1) = error(1);
            dist_min(1) = obst_estado(i, 1);
        end

        error(2) = abs(abs(sensor2_ang) - abs(obst_estado(i, 2)));

        if (error(2) < last_error(2)) &&  ...
           (sign(sensor2_ang) == sign(obst_estado(i, 2)) ||...
           (sign(obst_estado(i, 2)) == 0))

            obst_rob(2, :) = obst_estado(i, :);
            obst_pos(2, :) = obst_list(i, :);

            last_error(2) = error(2);
            dist_min(2) = obst_estado(i, 1);
        end

        error(3) = abs(abs(sensor3_ang) - abs(obst_estado(i, 2)));

        if (error(3) < last_error(3)) &&  ...
           (sign(sensor3_ang) == sign(obst_estado(i, 2)) ||...
            sign(obst_estado(i, 2)) == 0)

            obst_rob(3, :) = obst_estado(i, :);
            obst_pos(3, :) = obst_list(i, :);

            last_error(3) = error(3);
            dist_min(3) = obst_estado(i, 1);
        end
    end 
    
    obst.estado = obst_rob;
    obst.pos = obst_pos;
    
end
