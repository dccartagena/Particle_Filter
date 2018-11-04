function theta = get_ang(x)
    if x > pi
        theta = x - 2*pi;
    elseif x < -pi
        theta = x + 2*pi;
    else
        theta = x;
    end
end