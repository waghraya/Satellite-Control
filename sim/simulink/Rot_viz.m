close all;
% -------------------------
% Parse the data from Simulink output
% -------------------------
t = out.tout;
x_b = [out.simout.Data(:,1), out.simout.Data(:,4), out.simout.Data(:,7)];
y_b = [out.simout.Data(:,2), out.simout.Data(:,5), out.simout.Data(:,8)];
z_b = [out.simout.Data(:,3), out.simout.Data(:,6), out.simout.Data(:,9)];

% -------------------------
% Prepare the inertial frame (fixed)
% -------------------------
X_i = [1;0;0];  % red
Y_i = [0;1;0];  % green
Z_i = [0;0;1];  % blue

% -------------------------
% Initialize figure for animation
% -------------------------
figure;
hold on; grid on; axis equal;
xlabel('X'); ylabel('Y'); zlabel('Z');
xlim([-1 1]); ylim([-1 1]); zlim([-1 1]);
view(135, 30);

% Plot inertial frame (fixed)
quiver3(0,0,0,X_i(1),X_i(2),X_i(3),1,'r','LineWidth',2);
quiver3(0,0,0,Y_i(1),Y_i(2),Y_i(3),1,'g','LineWidth',2);
quiver3(0,0,0,Z_i(1),Z_i(2),Z_i(3),1,'b','LineWidth',2);

% Initialize body frame arrows at t=1
hX = quiver3(0,0,0,x_b(1,1),x_b(2,1),x_b(3,1),1,'r','LineWidth',2,'MaxHeadSize',0.5);
hY = quiver3(0,0,0,y_b(1,1),y_b(2,1),y_b(3,1),1,'g','LineWidth',2,'MaxHeadSize',0.5);
hZ = quiver3(0,0,0,z_b(1,1),z_b(2,1),z_b(3,1),1,'b','LineWidth',2,'MaxHeadSize',0.5);

% -------------------------
% Prepare GIF writer
% -------------------------
gif_name = 'attitude_animation.gif';
gif_delay = 0.01;
first_frame = true;

for k = 1:length(t)
    % Update body axes
    set(hX,'UData',x_b(k,1),'VData',x_b(k,2),'WData',x_b(k,3));
    set(hY,'UData',y_b(k,1),'VData',y_b(k,2),'WData',y_b(k,3));
    set(hZ,'UData',z_b(k,1),'VData',z_b(k,2),'WData',z_b(k,3));
    
    drawnow;

    % Capture frame
    frame = getframe(gcf);
    img = frame2im(frame);   % RGB image (no colormap)
    
    % Convert to indexed image for GIF
    [imind, map] = rgb2ind(img, 256);

    if first_frame
        imwrite(imind, map, gif_name, 'gif', 'LoopCount', Inf, 'DelayTime', gif_delay);
        first_frame = false;
    else
        imwrite(imind, map, gif_name, 'gif', 'WriteMode', 'append', 'DelayTime', gif_delay);
    end
end


% -------------------------
% Animate the body frame over time
% -------------------------
for k = 1:length(t)
    % Update body axes
    set(hX,'UData',x_b(k,1),'VData',x_b(k,2),'WData',x_b(k,3));
    set(hY,'UData',y_b(k,1),'VData',y_b(k,2),'WData',y_b(k,3));
    set(hZ,'UData',z_b(k,1),'VData',z_b(k,2),'WData',z_b(k,3));

    drawnow;

    % -------------------------
    % Save current frame to GIF
    % -------------------------
    frame = getframe(gcf);
    [im, map] = frame2im(frame);

    if first_frame
        imwrite(im, map, gif_name, 'gif', 'LoopCount', Inf, 'DelayTime', gif_delay);
        first_frame = false;
    else
        imwrite(im, map, gif_name, 'gif', 'WriteMode', 'append', 'DelayTime', gif_delay);
    end

    pause(0.01);  % Adjust animation playback speed
end