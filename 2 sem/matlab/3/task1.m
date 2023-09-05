eps = 0.0001;

F = @(x)(x.^3 + 3 * x - 1);
F2 = @(x)(1-x.^3)./3;

dF = @(x) ( 1*x.^2 + 3);
x = (-10:0.001:10);

plot(x, F(x));
grid on;

a = 0;
b = 1;


result1 = bisection(F, a, b, eps);
result2 = newton(F, dF, a, eps);
result3 = simpleIteration(F2, result1, eps);


function x0 = bisection(F, a, b, eps)
    while abs(a - b) > eps
       x0 = (a + b) / 2; 
       if ((F(x0) * F(a)) < 0) 
           b = x0; 
       else
           a = x0;
       end
    end
end



function x = newton(f,df,x0,eps)

x = x0; % initialize
err = 1;
    while err > eps
        x_prev = x;
        x = x_prev - f(x_prev)./df(x_prev);
        err = abs(x-x_prev);
    end
end



function x = simpleIteration(f,x0,eps)
    x = x0;
    err = eps+1;
    while err > eps
        x_prev = f(x);
        x = x_prev;
        err = abs(x-x_prev);
    end
end


