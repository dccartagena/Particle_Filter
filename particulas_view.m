function particulas_view(particulas)
%     particulas = rand(1000, 3);
%     particulas(:, 3) = pi*particulas(:, 3);
    dpx = 3*cos(particulas(3, :));
    dpy = 3*sin(particulas(3, :));
    quiver(particulas(1, :),particulas(2, :),dpx,dpy,0)
end