FROM openmodelica/openmodelica:v1.22.2-minimal

# Создаем директорию для моделей
RUN mkdir -p /app

# Копируем модель и скрипт в контейнер
COPY CoffeeCooling.mo /app/CoffeeCooling.mo
COPY simulate.mos /app/simulate.mos

# Устанавливаем рабочую директорию
WORKDIR /app

# Запускаем симуляцию через скрипт
CMD ["omc", "simulate.mos"]