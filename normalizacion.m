function B = normalizacion(A)
    factor = max(A(:)) - min(A(:));
    B = (A - min(A(:)))/factor;
end