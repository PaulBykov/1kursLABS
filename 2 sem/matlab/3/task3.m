eps = 0.00001;
F = @(x)(1-x.^3)./3;
x = (-10:0.001:10);
plot(x, F(x));
grid on;
a = 0;
b = 1;

Result3 = simpleIteration(F, a, eps);


function x = simpleIteration(f,x0,eps)
x = x0; % initialize
err = 1;
while err > eps
x_prev = f(x);
x = x_prev;
err = abs(x-x_prev);
end
end

