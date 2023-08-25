% Leer el archivo CSV
data = dlmread("resultados.csv", ";");

% Obtener los datos de las columnas
x_data = data(:, 1);
y_data = data(:, 2);

% Crear una línea de color rosa que une los puntos
plot(x_data, y_data, 'm-', 'LineWidth', 2);

xlabel('Número de Datos');
ylabel('Tiempo de Ejecución (ms)');
title('Big O en Octave');
grid on;

% Pausa durante 5 segundos para visualizar la gráfica
pause(10);
