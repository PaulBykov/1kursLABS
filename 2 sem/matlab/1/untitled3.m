f = @(x) (exp(-2 * x.^2 + x - 1));
n = 10;
a = -1;
b = 5;

s1 = trapesoid(a, b, n, f);
s2 = integral(f, a, b);

err_abs1 = abs(s2 - s1);
err_rel1 = err_abs1 / s2;

s3 = rectangle(a, b, n, f);

err_abs2 = abs(s2 - s3);
err_rel2 = err_abs2 / s2;

s4 = simson(a, b, n, f);

err_abs3 = abs(s2 - s4);
err_rel3 = err_abs3 / s2;

function sum= trapesoid(a, b, n, f)
    h = (b - a) / n;
    x = a;
    sum = 0;
    while (x <= b - h)
        sum = sum + ((f(x) + f(x + h)) * h/2);
        x = x + h;
    end
end



function sum = rectangle(a, b, n, f)
    h = (b - a) / n;
    x = a;
    sum = 0;
    while (x <= b - h)
        sum = sum + f(x + h / 2) * h;   
        x = x + h;
    end
end


function sum = simson(a, b, n, f)
    h = (b - a) / n;
    x = a;
    sum = 0;
    while (x <= b - h)
        sum = sum + (f(x) +  4 * f(x + h) + f(x + 2 * h)) * h/3;   
        x = x + 2 * h;
    end

end
