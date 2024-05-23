# Laboratorio 8
Este laboratorio consiste en práctica comandos de SQL mediante la página https://www.sql-practice.com/, el cuál trae ejercicios por hacer que se utilizaron como preguntas de práctica.

## Integrantes
Kevin Campos Castro

Mariana Solís Gonzáles

Esteban Aragón Herrera

Susan Morales

# Solución de Preguntas
2 de los compañer@s mandaron imágenes para las soluciones de sus preguntas, por lo que no me dió tiempo de pasarlos a markdown, solamente se agrega el markdown de uno de los compañeros que lo habían enviado y el que hice personalemente, lo demás se encuentra en un pdf por lo explicado anteriormente. 

A continuación se agrega el enunciado de la pregunta, su solución y a qué base de datos pertenece, 
## hospital.db

1. Write a query to find list of patients first_name, last_name, and allergies where allergies are not null and are from the city of 'Hamilton'
```
SELECT first_name, last_name, allergies
FROM patients
where 
    allergies is not null
    and city = 'Hamilton'
```
2. Show patient_id, first_name, last_name from patients whose does not have any records in the admissions table. (Their patient_id does not exist in any admissions.patient_id rows.)
```
SELECT patients.patient_id, patients.first_name, patients.last_name 
FROM patients
where patients.patient_id not in (
  select admissions.patient_id
  from admissions)
```
3. Display patient's full name,
height in the units feet rounded to 1 decimal,
weight in the unit pounds rounded to 0 decimals,
birth_date,
gender non abbreviated.
Convert CM to feet by dividing by 30.48.
Convert KG to pounds by multiplying by 2.205.
```
SELECT
    concat(first_name, ' ', last_name) AS 'patient_name', 
    ROUND(height / 30.48, 1) as 'height "Feet"', 
    ROUND(weight * 2.205, 0) AS 'weight "Pounds"', birth_date,
CASE
    WHEN gender = 'M' THEN 'MALE' 
  ELSE 'FEMALE' 
END AS 'gender_type'
from patients
```
4. We need a breakdown for the total amount of admissions each doctor has started each year. Show the doctor_id, doctor_full_name, specialty, year, total_admissions for that year.
```
SELECT
  d.doctor_id as doctor_id,
  CONCAT(d.first_name,' ', d.last_name) as doctor_name,
  d.specialty,
  YEAR(a.admission_date) as selected_year,
  COUNT(*) as total_admissions
FROM doctors as d
  LEFT JOIN admissions as a ON d.doctor_id = a.attending_doctor_id
GROUP BY
  doctor_name,
  selected_year
ORDER BY doctor_id, selected_year
```

## northwind.db
5. Show the category_name and the average product unit price for each category rounded to 2 decimal places.
```
SELECT Round(AVG(unit_price), 2) as average_price, -- Calcular promedio y usar 2 decimales
SUM(units_in_stock) as total_unit_stock, -- Total de units in stock
SUM(discontinued) as discontinued_products -- Total de productos descontinuados
FROM products;
```

6. Show the first_name, last_name. hire_date of the most recently hired employee.
```
SELECT first_name, last_name,
max(hire_date) AS hire_date -- Determinar el empleado más reciente
FROM employees;
```

7. Show the city, company_name, contact_name from the customers and suppliers table merged together.
```
Create a column which contains 'customers' or 'suppliers' depending on the table it came from.
select city, company_name, contact_name, 'customers' as table_from -- Agregar en columna table_from la tabla de la que viene (customers)
from customers
	union -- Unir ambas tablas
select city, company_name, contact_name, 'suppliers' -- Agregar en columna table_from la tabla de la que viene (suppliers)
from suppliers
```

8. Show how much money the company lost due to giving discounts each year, order the years from most recent to least recent. Round to 2 decimal places.
```
SELECT 
YEAR(orders.order_date) AS 'order_year' ,
-- Calcular total de descuentos y solo usar 2 decimales
ROUND(SUM(products.unit_price * order_details.quantity * order_details.discount), 2) AS 'discount_amount' 

from orders
-- Unir tablas solo donde el id del producto o orden coincide 
JOIN order_details ON orders.order_id = order_details.order_id
JOIN products ON order_details.product_id = products.product_id

-- Ordenar años de reciente a menos reciente
group by YEAR(orders.order_date)
order by order_year desc;
```
