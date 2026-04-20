import pandas as pd

# Crear los datos de la tabla
data = {
    "Mes": ["Mes 1", "Mes 2", "Mes 3", "Mes 4", "Mes 5", "Mes 6"],
    "Sueldo (Q)": [5275, 5275, 5275, 5275, 5275, 5275],
    "Reembolso Viáticos (Q)": [0, 2550, 2550, 2550, 2550, 2550],
    "Total Disponible (Q)": [5275, 8150, 11025, 13900, 15775, 18650],
    "Gastos Personales (Q)": [2400, 2400, 2400, 2400, 2400, 2400],
    "Comisiones (Adelanto Q)": [2550, 2550, 2550, 2550, 2550, 2550],
    "Saldo Final (Q)": [325, 3200, 6075, 8950, 11825, 14700],
    "¿Distribución Fija?": ["No", "Parcial", "Sí", "Sí", "Sí", "Sí"]
}

# Crear el DataFrame
df = pd.DataFrame(data)

# Guardar en un archivo Excel
excel_path = "/mnt/data/Proyeccion_Financiera_Comisiones.xlsx"
df.to_excel(excel_path, index=False)

excel_path
