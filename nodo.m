classdef nodo
    properties
        parent % Padre del nodo
        map % Mapa del nodo
        child % Hijos del nodo
        value % Valor del nodo
        pos % Posicion del robot
        prof % Profundidad del nodo
    end
    
    methods
        
        function obj = nodo(mapa)
            obj.parent = [];
            obj.map = mapa;
            obj.child = [];
            obj.value = [];
            obj.pos = [];
            obj.prof = 0;
        end
                
        function check = islisted(obj, listarbol)
            check = 0;
            index = length(listarbol);
            
            for j = 1:index
                if obj.map == listarbol(j).map
                    check = 1;
                end
            end
        end
        
    end
end