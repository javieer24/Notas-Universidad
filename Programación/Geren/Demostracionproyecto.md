# 📋 Guía de Demostración — Odoo SmartHome Hub
### Laboratorio SOG1 N — Grupo 8 — 2026
### URL del sistema: smarthome-hub.odoo.com

---

## ✅ Checklist de todo lo configurado

| Elemento | Cantidad | Estado |
|---|---|---|
| Proveedores | 5 | ✅ Listo |
| Clientes | 5 | ✅ Listo |
| Productos | 15 | ✅ Listo |
| Relación Proveedor-Producto | 5 proveedores × 3 productos | ✅ Listo |
| Reglas de Reordenamiento | 5 | ✅ Listo |
| Pipeline CRM | 5 oportunidades | ✅ Listo |
| Plantillas de Correo | 2 | ✅ Listo |

---

## 👥 MOSTRAR PROVEEDORES

**Ruta:** Compras → Órdenes → Proveedores

| # | Nombre | NIT | Teléfono | Correo |
|---|---|---|---|---|
| 1 | TechDistrib GT | 12345678-1 | +502 2234 5678 | ventas@techdistrib.gt |
| 2 | IoT Solutions Guatemala | 23456789-2 | +502 2345 6789 | contacto@iotsolgt.com |
| 3 | SmartTech Imports | 34567890-3 | +502 2456 7890 | info@smarttechgt.com |
| 4 | DigiHome Supply | 45678901-4 | +502 2567 8901 | pedidos@digihome.gt |
| 5 | HomeTech Mayorista | 56789012-5 | +502 2678 9012 | mayoreo@hometech.gt |

**Qué mostrar:**
1. Entrar a Compras → Proveedores
2. Mostrar la lista con los 5 proveedores
3. Abrir uno y mostrar sus datos completos (nombre, NIT, dirección, teléfono, correo)

---

## 👤 MOSTRAR CLIENTES

**Ruta:** Ventas → Órdenes → Clientes

| # | Nombre | Teléfono | Dirección | NIT |
|---|---|---|---|---|
| 1 | Andrea Sofía Ramírez Fuentes | +502 5534 1122 | Zona 10, Ciudad de Guatemala | 78901234-5 |
| 2 | Marco Antonio Cifuentes López | +502 5678 3344 | Zona 14, Ciudad de Guatemala | 89012345-6 |
| 3 | Daniela Mishel Ajú Xitumul | +502 5812 5566 | Mixco, Guatemala | 90123456-7 |
| 4 | Fernando José Ruiz Morales | +502 5923 7788 | Villa Nueva, Guatemala | 01234567-8 |
| 5 | Claudia Patricia Méndez Soto | +502 6034 9900 | Zona 5, Ciudad de Guatemala | 12345678-9 |

**Qué mostrar:**
1. Entrar a Ventas → Clientes
2. Mostrar la lista con los 5 clientes
3. Abrir uno y mostrar sus datos completos (nombre, teléfono, dirección, NIT)

---

## 📦 MOSTRAR PRODUCTOS

**Ruta:** Inventario → Productos → Productos

| Ref | Nombre | Tipo | Precio | Costo | Categoría |
|---|---|---|---|---|---|
| SHH-001 | Foco Inteligente LED Wi-Fi (9W) | Bienes | Q89 | Q45 | Iluminación |
| SHH-002 | Tira LED RGB Inteligente 5m | Bienes | Q149 | Q75 | Iluminación |
| SHH-003 | Enchufe Inteligente Wi-Fi | Bienes | Q119 | Q58 | Control |
| SHH-004 | Interruptor Inteligente Doble | Bienes | Q175 | Q88 | Control |
| SHH-005 | Cámara de Seguridad Interior 1080p | Bienes | Q349 | Q175 | Seguridad |
| SHH-006 | Cámara de Seguridad Exterior IP66 2K | Bienes | Q549 | Q275 | Seguridad |
| SHH-007 | Timbre Inteligente con Cámara Wi-Fi | Bienes | Q489 | Q245 | Seguridad |
| SHH-008 | Sensor de Movimiento PIR Zigbee | Bienes | Q129 | Q62 | Sensores |
| SHH-009 | Sensor de Puerta/Ventana Zigbee | Bienes | Q99 | Q48 | Sensores |
| SHH-010 | Sensor de Humo y Gas Inteligente | Bienes | Q219 | Q110 | Sensores |
| SHH-011 | Bocina Inteligente con Asistente de Voz | Bienes | Q399 | Q200 | Audio |
| SHH-012 | Hub Central Zigbee/Z-Wave | Bienes | Q599 | Q300 | Control |
| SHH-013 | Termostato Inteligente Wi-Fi | Bienes | Q699 | Q350 | Climatización |
| SHH-014 | Cerradura Inteligente con Huella y App | Bienes | Q899 | Q450 | Seguridad |
| SHH-015 | Instalación y Configuración Smart | Servicio | Q250 | Q80 | Servicios |

**Qué mostrar:**
1. Entrar a Inventario → Productos
2. Mostrar la lista con los 15 productos
3. Abrir un producto y mostrar la pestaña **"Compras"** para ver el proveedor asignado

---

## 🛒 MOSTRAR RELACIÓN PROVEEDOR-PRODUCTO

**Ruta:** Inventario → Productos → abrir cualquier producto → pestaña "Compras"

| Proveedor | Productos que surte |
|---|---|
| TechDistrib GT | Foco LED, Tira LED, Enchufe Inteligente, Interruptor Doble |
| IoT Solutions Guatemala | Cámara Interior, Cámara Exterior, Timbre con Cámara |
| SmartTech Imports | Sensor Movimiento, Sensor Puerta, Sensor Humo y Gas |
| DigiHome Supply | Bocina Inteligente, Hub Central, Termostato |
| HomeTech Mayorista | Cerradura Inteligente, Servicio de Instalación |

**Qué mostrar:**
1. Abrir el producto Foco Inteligente LED Wi-Fi
2. Ir a la pestaña **"Compras"**
3. Mostrar que tiene asignado a TechDistrib GT con precio y plazo

---

## 🔄 MOSTRAR REGLAS DE REORDENAMIENTO

**Ruta:** Inventario → Operaciones → Reabastecimiento

| Producto | A la mano | Mínimo | Máximo |
|---|---|---|---|
| Foco Inteligente LED Wi-Fi | 50 | 5 | 30 |
| Tira LED RGB Inteligente 5m | 40 | 5 | 25 |
| Cámara de Seguridad Interior 1080p | 25 | 3 | 15 |
| Sensor de Movimiento PIR Zigbee | 45 | 5 | 30 |
| Cerradura Inteligente con Huella y App | 10 | 2 | 10 |

**Qué mostrar:**
1. Entrar a Inventario → Operaciones → Reabastecimiento
2. Mostrar las 5 reglas con sus cantidades mínimas y máximas
3. Explicar que cuando el stock baja del mínimo, Odoo genera automáticamente la orden al proveedor

---

## 📊 MOSTRAR PIPELINE CRM

**Ruta:** CRM → Flujo

| Cliente | Etapa |
|---|---|
| Andrea Sofía Ramírez Fuentes | Nuevo |
| Marco Antonio Cifuentes López | Calificado |
| Claudia Patricia Méndez Soto | Calificado |
| Daniela Mishel Ajú Xitumul | Propuesta |
| Fernando José Ruiz Morales | Ganado |

**Qué mostrar:**
1. Entrar al módulo CRM
2. Mostrar el tablero Kanban con las 4 columnas
3. Señalar que cada cliente está en una etapa diferente del proceso de venta

---

## ✉️ MOSTRAR PLANTILLAS DE CORREO

**Ruta:** smarthome-hub.odoo.com/odoo/email-templates?debug=1

| # | Nombre | Asunto | Tipo |
|---|---|---|---|
| 1 | SmartHome Hub - Promoción Especial | ¡Oferta especial SmartHome Hub solo esta semana! | Promoción |
| 2 | SmartHome Hub - Fidelización y Agradecimiento | Gracias por confiar en SmartHome Hub | Fidelización |

**Qué mostrar:**
1. Ir a la URL con debug=1
2. Buscar las 2 plantillas creadas
3. Abrir cada una y mostrar el contenido del correo

---

## ⚠️ Tips para la evaluación

- Practica la ruta a cada sección antes de que te evalúen
- Si el auxiliar pide ver algo específico, ya sabes exactamente dónde está
- Habla con seguridad explicando qué hace cada módulo
- Si te preguntan por qué un módulo, menciona su relación con ERP, SCM o CRM
