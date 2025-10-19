model CoolingCoffee
  parameter Real T_start = 90;
  parameter Real T_room = 25;
  parameter Real h = 15;
  parameter Real A = 0.03;
  parameter Real m_coffee = 0.2;
  parameter Real c_coffee = 4180;
  parameter Real m_cup = 0.15;
  parameter Real c_cup = 800;
  Real T(start = T_start);
  Real Q_flow;
equation 
  (m_coffee * c_coffee + m_cup * c_cup) * der(T) = -Q_flow;
  Q_flow = h * A * (T - T_room);
end CoolingCoffee;