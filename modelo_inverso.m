function [vl, vr] = modelo_inverso(dchi, chi)
    l = 259.5; %Distancia entre centros de ruedas [mm]
    % r = 32; %Radio de las llantas [mm]
    
    theta = chi(3);
    
    % Matriz jacobiana del sistema
    J = [-sin(theta)/2 -sin(theta)/2; 
          cos(theta)/2  cos(theta)/2;
              -1/l          1/l    ];
          
  p = ((J'*J)\J')*dchi;
  
  A = [1 -l/2;
       1  l/2];
   
  V_llanta = A*p;
  vl = V_llanta(1);
  vr = V_llanta(2);
  
end