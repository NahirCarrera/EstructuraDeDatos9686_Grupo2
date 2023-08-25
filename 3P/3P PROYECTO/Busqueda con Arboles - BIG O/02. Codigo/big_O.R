# Cargar el paquete ggplot2
library(ggplot2)

# Leer el archivo CSV
data <- read.csv("resultados.csv", header = TRUE, sep = ";")

# Obtener los nombres de las columnas
x_name <- names(data)[1]
y_name <- names(data)[2]

# Crear la gráfica utilizando ggplot2 con aes()
plot <- ggplot(data, aes(x = !!sym(x_name), y = !!sym(y_name))) +
  geom_line(color = "purple", linewidth = 1.5) +  # Línea de color morado y más gruesa
  labs(x = x_name, y = y_name) +
  ggtitle("Big O en R")

# Mostrar la gráfica en una ventana gráfica independiente
if (Sys.info()["sysname"] == "Windows") {
  windows()
} else {
  x11()
}

# Mostrar la gráfica en la ventana gráfica independiente
print(plot)

# Pausa para que la ventana no se cierre inmediatamente
Sys.sleep(10)  # Pausa de 10 segundos (ajusta el valor según lo necesario)
