FROM openmodelica/openmodelica:v1.22.2-minimal

# Создаем директорию для приложения
RUN mkdir -p /app

# Копируем модель и скрипт в контейнер
COPY ESP32_CAM_Thermal_Energy.mo /app/ESP32_CAM_Thermal_Energy.mo
COPY simulate.mos /app/simulate.mos

# Устанавливаем рабочую директорию
WORKDIR /app

# Запускаем симуляцию через скрипт
CMD ["omc", "simulate.mos"]