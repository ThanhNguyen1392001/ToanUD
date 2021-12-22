% chuong trinh lam tron 1 tin hieu de khu nhieu 
% dung bo loc lay trung binh cong 3 diem (3-points moving-averaging filter)

% co PTSP: y[n] = 1/3(x[n]+x[n-1]+x[n-2])

% sinh tin hieu bi lan voi nhieu cong (additive noise)
clear all;
clf;                            % clear figures
L = 51;                         % do dai tin hieu
n = 0:L-1;                      % bien thoi gian roi rac
d = 0.5*randn(1,L);             % sinh tin hieu Gausian noise d[n] (0.5 la bien do nhieu)
s = 2*n.*(0.9.^n);              % sinh tin hieu goc s[n] = 2n(0.9)^n
x = s + d;                      % tin hieu co nhieu x[n]=s[n]+d[n]

% problem: co tin hieu bi nhieu x[n], di khoi phuc lai tin hieu goc s[n]
figure(1)                    
hold on
subplot(3,1,1)                 
plot(n,d,'r-',n,s,'k--',n,x,'b-.'); % ve do thi d[n],s[n],x[n]
xlabel('Thoi gian');
ylabel('Bien do');
legend('d[n]','s[n]','x[n]');
title('Noise d[n] vs. original s[n] vs. noisy signals x[n]');

% cach 1: cai dat he thong bang cach dich thoi gian va tinh TBC cua 3 tin hieu
x1 = [x];              % x1[n] = x[n]
x2 = [0, x(1:L-1)];    % x2[n] = x[n-1]
x3 = [0, 0, x(1:L-2)];  % x3[n] = x[n-2]

subplot(3,1,2)
% ve do thi x[n-1],x[n],x[n+1]
plot(n,x1,'r-.',n,x2,'b-.',n,x3,'k-.');
xlabel('Thoi gian');
ylabel('Bien do');
legend('x[n]','x[n-1]','x[n-2]');
title('time-shifted signals of x[n]');

% lenh cai dat he thong
y1 = 1/3*(x1+x2+x3);     
subplot(3,1,3)
% ve do thi y1[n] vs. s[n]
plot(n,y1(1:L),'r-',n,s(1:L),'b-');
xlabel('Thoi gian');
ylabel('Bien do');
legend('y1[n]','s[n]');
title('3-points smoothed y1[n] vs. original signal s[n]');

% cach 2: cai dat he thong bang cach dung ham tinh tong chap conv()
% ghep noi tiep he som 1 don vi va he lay TB cong nhan qua
h1 = 1/3 * ones(1,3);    % h[n] = [1/3, 1/3, 1/3]
y2 = conv(x1, h1);         % y2[n] = x1[n] * h[n]
% ve do thi y2[n] vs. s[n]
figure(2)
plot(n,y2(1:L),'r-',n,s(1:L),'b-');
xlabel('Thoi gian');
ylabel('Bien do');
legend('y2[n]','s[n]');
title('3-points smoothed y2[n] vs. original signal s[n]');

% ve do thi xep chong y1[n] va y2[n] de test
figure(3)
hold on
plot(n,y1(1:L),'r-',n,y2(1:L),'b--');
xlabel('Thoi gian');
ylabel('Bien do');
legend('y1[n]','y2[n]');
title('cach1  vs. cach2');


% Bo sung cach 3: su dung vong lap
% y[n] = 1/3(x[n]+x[n-1]+x[n-2])
% num = [1/3, 1/3, 1/3];
% den = [1,0,0];
% h2 = impz(num,den,L-1); => 50

M = length(h1);
N = length(x);
l = M+N-1;
y3 = zeros(1,l);
for m = 1: M
    for e = 1:N
        k=e+m-1;
        y3(k)=y3(k)+h1(m)*x(e);
    end
end

% ve do thi xep chong y2[n], y3[n] de test
figure(4)
hold on
plot(n,y2(1:L),'b--',n, y3(1:L),'m*');
xlabel('Thoi gian');
ylabel('Bien do');
legend('y2[n]', 'y3[n]');
title('cach2 vs. cach 3');

% cach 4: dung ham cai dat bo loc filter()???










