clc; close all;

t = out.tout;
Roll = out.simout1.Data(:,1);
Pitch = out.simout1.Data(:,2);
Yaw = out.simout1.Data(:,3);

figure;

subplot(3,1,1);
plot(t, Roll);
ylabel('Roll [deg]');

subplot(3,1,2);
plot(t,Pitch);
ylabel('Pitch [deg]');

subplot(3,1,3);
plot(t,Yaw);
xlabel('Time [s]'); ylabel('Yaw [deg]');