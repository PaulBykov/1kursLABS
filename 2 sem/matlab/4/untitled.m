A = [0, 0, 0, 0;
     0, 0, 0, 0;
     0, 0, 0, 0;
     0, 0, 0, 0];

B = [0; 3; 3; 5];
n = 4;

if(det(A) == 0)
    disp("Определитель равен 0");
else
    X = inv(A) * B;
    disp(X);
end


% Прямой ход метода Гаусса
for k = 1:n-1
    for i = k+1:n
        factor = A(i,k)/A(k,k);
        A(i,k+1:n) = A(i,k+1:n) - factor*A(k,k+1:n);
        B(i) = B(i) - factor*B(k);
    end
end

% Обратный ход метода Гаусса
x = zeros(n,1);
x(n) = B(n)/A(n,n);
for k = n-1:-1:1
    x(k) = (B(k) - A(k,k+1:n)*x(k+1:n))/A(k,k);
end


disp(x); % Вывод решения

