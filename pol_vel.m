function [V, a_f] = pol_vel(v_0, v_f, a_0, t, dt)
    t0 = 0;
    tf = 3;

    a_f = (v_f - v_0)/dt;

    C = [1 0  0    0   ;
         1 tf tf^2 tf^3;
         0 1  0    0   ;
         0 1  2*tf   3*tf^2;];
     
     X = [v_0 v_f a_0 a_f]';
     
     A = C\X;
     
     V = A(1) + A(2)*t + A(3)*t^2 + A(4)*t^3; 
     
end