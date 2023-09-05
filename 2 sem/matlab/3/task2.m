eps = 0.00001;
F = @(x)(x.^3 + 3 * x - 1);
dF = @(x) ( 1*x.^2 + 3);
x = (-10:0.001:10);
%plot(x, F(x));


a = -2;
b = 2;


C = newton(F,dF,b,eps);





