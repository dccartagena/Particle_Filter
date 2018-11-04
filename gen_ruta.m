function [mapa, mapa_ruta, camino, robot] = gen_ruta(tipo)
%% Funcion para generar rutas
    %tipo = 5;
    mapa = mapas(tipo);
    [fila, columna] = size(mapa);
    
    [x_robot, y_robot] = find_robot(mapa, fila, columna);
    [x_meta, y_meta] = find_meta(mapa, fila, columna);
    
    robot = [x_robot y_robot];
    meta = [x_meta y_meta];
    
    [mapa_ruta, camino] = bus_heu(mapa, meta, robot);
    
    camino((all(camino==0,2)), :)=[];
    camino = flipud(camino);
    
    %mapa_ruta = flipud(mapa_ruta);
end

function [mapa_ruta, camino] = bus_heu(mapa, meta, robot)
   mapa_costo = gen_heuristica(mapa, meta);
   mapa_heu = gen_costo(mapa);
   mapa_sol = gen_sol(robot, meta, mapa);
    
   root = nodo(mapa);
   root.pos = robot;
   
   tree = root;
   issolved = 0;
   listedtree = [];
   profundidad = 0;
   
   ok = 0;
   while (issolved == 0) && (~isempty(tree))
       if ok == 0
           node = root;
           ok = 1;
       else
           node = nodohijo(besti);
       end
       %tree(end) = [];
       
       listedtree = [listedtree node];
       if checksol(node, mapa_sol) == 1
           break;
       else
           nodohijo = childgen(node, mapa_costo, mapa_heu);
           best_value = -1;
           if ~isempty(nodohijo)
               index = length(nodohijo);
               for i = 1:index
                   if ~isempty(nodohijo(i).value)
                       if nodohijo(i).value > best_value
                           best_value = nodohijo(i).value;
                           besti = i;
                           if (~nodohijo(besti).islisted(listedtree)) && (~nodohijo(besti).islisted(tree))
                               tree = [tree nodohijo(besti)];
                               node.child = [node.child nodohijo(besti)];
                               nodohijo(besti).parent = node;
                               nodohijo(besti).prof = profundidad;
                               profundidad = profundidad + 1;
                           end
                       end
                   end
               end
           end
       end
   end
   
   [mapa_ruta, camino] = print_ruta(mapa, node);
%    figure; imagesc(mapa_ruta); 
%    figure; imagesc(mapa_heu);
%    figure; imagesc(mapa_costo);
end

function [mapa_ruta, camino] = print_ruta(mapa, node)

    mapa_ruta = mapa;
    camino = zeros(node.prof, 2); %Error
    k = 1;
    if ~isempty(node)
         %disp('Nodos recorridos:');
         %disp(node.prof);
         while ~isempty(node.parent)
             camino(k, :) = node.pos; % Error
             node = node.parent;
             k = k + 1; % Error
         end
         
         index = length(camino);
         
         for i = 1:index
             if (camino(i, 2) > 0) && (camino(i, 1) > 0)
                mapa_ruta(camino(i, 2), camino(i, 1)) = 2;
             end
         end
    end

end

function issol = checksol(node, solucion)
%% Funcion para comprobar si ya se llego a alguna solucion
    index = size(solucion, 3);
    issol = 0;
    
    for i = 1:index
        if (node.map == solucion(:, :, i))
            issol = 1;
        end
    end
end

function nodohijo = childgen(node, mapa_costo, mapa_heu)
    nodohijo = [movright(node.map) movediag1(node.map) movleft(node.map) movediag2(node.map)...
                movup(node.map) movediag4(node.map) movdown(node.map) movediag3(node.map)];
       
    index = length(nodohijo);
    
    for i = 1:index
        if ~isempty(nodohijo(i))
            costo = mapa_costo(nodohijo(i).pos(2), nodohijo(i).pos(1));
            heur = mapa_heu(nodohijo(i).pos(2), nodohijo(i).pos(1));
            nodohijo(i).value = costo + heur;
        end
    end
end

function node = movright(mapa)
    [Y, X] = size(mapa);
    [x_rob, y_rob] = find_robot(mapa, Y, X);
    robot = [x_rob, y_rob];
    
    newmap = mapa;
    
    if (robot(1) + 1 <= X)
        newrobot = [(robot(1) + 1) robot(2)];
        node = move(newmap, mapa, newrobot, robot);
    else
        node = [];
    end
end

function node = movediag1(mapa) % <---------
    [Y, X] = size(mapa);
    [x_rob, y_rob] = find_robot(mapa, Y, X);
    robot = [x_rob, y_rob];
    
    newmap = mapa;
    
    if (robot(1) + 1 <= Y) && (robot(2) - 1 <= 1)
        newrobot = [(robot(1)) (robot(2) - 1)];
        node = move(newmap, mapa, newrobot, robot);
    else
        node = [];
    end
end

function node = movleft(mapa)
    [Y, X] = size(mapa);
    [x_rob, y_rob] = find_robot(mapa, Y, X);
    robot = [x_rob, y_rob];
    
    newmap = mapa;
    
    if (robot(1) - 1 >= 1)
        newrobot = [(robot(1) - 1) robot(2)];
        node = move(newmap, mapa, newrobot, robot);
    else
        node = [];
    end
end

function node = movediag2(mapa) % <---------
    [Y, X] = size(mapa);
    [x_rob, y_rob] = find_robot(mapa, Y, X);
    robot = [x_rob, y_rob];
    
    newmap = mapa;
    
    if (robot(1) - 1 >= 1) && (robot(2) - 1 >= 1)
        newrobot = [(robot(1) - 1) (robot(2) - 1)];
        node = move(newmap, mapa, newrobot, robot);
    else
        node = [];
    end
end

function node = movdown(mapa)
    [Y, X] = size(mapa);
    [x_rob, y_rob] = find_robot(mapa, Y, X);
    robot = [x_rob, y_rob];
    
    newmap = mapa;
    
    if (robot(2) - 1 >= 1)
        newrobot = [robot(1) (robot(2) - 1)];
        node = move(newmap, mapa, newrobot, robot);
    else
        node = [];
    end
end

function node = movediag3(mapa)
    [Y, X] = size(mapa);
    [x_rob, y_rob] = find_robot(mapa, Y, X);
    robot = [x_rob, y_rob];
    
    newmap = mapa;
    
    if (robot(1) - 1 >= 1) && (robot(2) + 1 <= Y)
        newrobot = [(robot(1) - 1) (robot(2) + 1)];
        node = move(newmap, mapa, newrobot, robot);
    else
        node = [];
    end
end

function node = movup(mapa)
    [Y, X] = size(mapa);
    [x_rob, y_rob] = find_robot(mapa, Y, X);
    robot = [x_rob, y_rob];
    
    newmap = mapa;
    
    if (robot(2) + 1 <= Y)
        newrobot = [robot(1) (robot(2) + 1)];
        node = move(newmap, mapa, newrobot, robot);
    else
        node = [];
    end
end

function node = movediag4(mapa) % <---------
    [Y, X] = size(mapa);
    [x_rob, y_rob] = find_robot(mapa, Y, X);
    robot = [x_rob, y_rob];
    
    newmap = mapa;
    
    if (robot(1) + 1 <= Y) && (robot(2) + 1 <= Y)
        newrobot = [(robot(1) + 1) (robot(2) + 1)];
        node = move(newmap, mapa, newrobot, robot);
    else
        node = [];
    end
end

function Nnode = move(newmap, mapa, newrobot, robot)
    
    if newmap(newrobot(2), newrobot(1)) == 0
        newmap(newrobot(2), newrobot(1)) = 2;
        newmap(robot(2), robot(1)) = 0;
        if max(max(newmap ~= mapa))
            Nnode = nodo(newmap);
            Nnode.pos = newrobot;
        else
            Nnode = [];
        end
    else
        Nnode = [];
    end
end

function mapa_heu = gen_costo(mapa)
    %dbstop if error
    
    obst = find_obstaculos(mapa);
    n_obst = size(obst, 1);
    [fila, columna] = size(mapa);
    
    mapa_heu = zeros(fila, columna);
    for i = 1:n_obst
        for j = 1: obst(i, 2)
            for k = 1: obst(i, 1)
                if mapa(j, k) ~= 1
                    val = sqrt((obst(i, 2) - j)^2 + (obst(i, 1) - k)^2);
                    if mapa_heu(j, k) == 0
                        mapa_heu(j, k) = val;
                    else
                        mapa_heu(j, k) = min(val, mapa_heu(j, k));
                    end
                end
            end
        end
        
        for j = 1: obst(i, 2)
            for k = obst(i, 1): columna
                if mapa(j, k) ~= 1
                    val = sqrt((obst(i, 2) - j)^2 + (obst(i, 1) - k)^2);
                    if mapa_heu(j, k) == 0
                        mapa_heu(j, k) = val;
                    else
                        mapa_heu(j, k) = min(val, mapa_heu(j, k));
                    end
                end
            end
        end
        
        for j = obst(i, 2): fila
            for k = 1: obst(i, 1)
                if mapa(j, k) ~= 1
                    val = sqrt((obst(i, 2) - j)^2 + (obst(i, 1) - k)^2);
                    if mapa_heu(j, k) == 0
                        mapa_heu(j, k) = val;
                    else
                        mapa_heu(j, k) = min(val, mapa_heu(j, k));
                    end
                end
            end
        end
        
        for j = obst(i, 2): fila
            for k = obst(i, 1): columna
                if mapa(j, k) ~= 1
                    val = sqrt((obst(i, 2) - j)^2 + (obst(i, 1) - k)^2);
                    if mapa_heu(j, k) == 0
                        mapa_heu(j, k) = val;
                    else
                        mapa_heu(j, k) = min(val, mapa_heu(j, k));
                    end
                end
            end
        end
    end
    
    %mapa_heu = normalizacion(mapa_heu);
    
end

function mapa_costo = gen_heuristica(mapa, meta)
    [fila, columna] = size(mapa);
    
    map_costo_aux = zeros(fila, columna);
    
    x_meta = meta(1);
    y_meta = meta(2);
    
    for j = 1:fila
        for i = 1:columna
            map_costo_aux(j, i) = sqrt((i - x_meta)^2 + (j - y_meta)^2);
        end
    end
    
    max_value = max(max(map_costo_aux));
    max_matrix = max_value*ones(fila, columna);
    mapa_costo = abs(max_matrix - map_costo_aux);
    
    %mapa_costo = normalizacion(mapa_costo);
end

function mapa_sol = gen_sol(robot, meta, mapa)
    [fila, columna] = size(mapa);
    
    mapa_sol = repmat(mapa, [1 1 4]);
    mapa_sol(robot(2), robot(1), :) = 0;
    
    if (meta(1) - 1 >= 1) && (meta(2) >= 1)
        mapa_sol(meta(2), meta(1) - 1, 1) = 2;
    else
        mapa_sol(1, 1, 1) = 5;
    end
    
    if (meta(1) >= 1) && (meta(2) - 1 >= 1)
        mapa_sol(meta(2) - 1, meta(1), 2) = 2;
    else
        mapa_sol(1, 1, 2) = 5;
    end
    
    if (meta(1) + 1 <= columna) && (meta(2) <= fila)
        mapa_sol(meta(2), meta(1) + 1, 3) = 2;
    else
        mapa_sol(1, 1, 3) = 5;
    end
    
    if (meta(1) <= columna) && (meta(2) + 1 <= fila)
        mapa_sol(meta(2) + 1, meta(1), 4) = 2;
    else
        mapa_sol(1, 1, 4) = 5;
    end
    
    for i = 4:-1:1
        if mapa_sol(1, 1, i) == 5
            mapa_sol(:, :, i) = [];
        end
    end
end

function [x_rob, y_rob] = find_robot(map, fila, colum)
%% Funcion para encontrar la posicion del robot en el mapa
    for j = 1:fila
        for i = 1:colum
            if map(j, i) == 2
               x_rob = i;
               y_rob = j;
            end
        end
    end
end

function obst = find_obstaculos(mapa)
    [fila, columna] = size(mapa);
    
    obst = zeros(fila*columna, 2);
    k = 1;
    
    for j = 1:fila
        for i = 1:columna
            if mapa(j, i) == 1
                obst(k, :) = [i j];
                k = k + 1;
            end
        end
    end
    
    obst(k:end, :) = [];
end

function [x_meta, y_meta] = find_meta(map, fila, colum)
%% Funcion para encontrar la posicion de la meta en el mapa
    for j = 1:fila
        for i = 1:colum
            if map(j, i) == 3
               x_meta = i;
               y_meta = j;
            end
        end
    end
end