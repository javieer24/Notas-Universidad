# 📋 Guía Ejercicio Práctico — Odoo
### Laboratorio SOG1 N — Grupo 8 — 2026

---

## 🗺️ Flujo completo del ejercicio

```
Crear producto "Calificación"
        ↓
Agregar 10 unidades a la mano
        ↓
Crear regla de reordenamiento (mínimo 5)
        ↓
Asignar proveedor al producto
        ↓
Crear venta de 10 unidades
        ↓
Confirmar pedido de venta
        ↓
Crear factura
        ↓
Confirmar/Validar factura ✅
```

---

## 📦 PASO 1 — Crear el producto "Calificación"

**Dónde ir:** Inventario → Productos → Productos → Nuevo

| Campo | Valor |
|---|---|
| Nombre | Calificación |
| Tipo de producto | Bienes |
| Precio de venta | 100 |
| Costo | 50 |

**Guarda** antes de continuar al siguiente paso.

---

## 📊 PASO 2 — Agregar 10 unidades a la mano

**Dónde ir:** Dentro del producto "Calificación"

1. Arriba verás el botón **"Actualizar cantidad"** o **"0 A la mano"** — haz clic
2. Clic en **"Nuevo"**
3. En el campo **Cantidad** escribe **10**
4. Clic en **"Aplicar todo"**

> ✅ El producto ahora debe mostrar **"10 A la mano"**

---

## 🔄 PASO 3 — Crear regla de reordenamiento (mínimo 5)

**Dónde ir:** Inventario → Operaciones → Reabastecimiento → Nuevo

| Campo | Valor |
|---|---|
| Producto | Calificación |
| Mínimo | 5 |
| Máximo | 20 |

**Guarda** la regla.

> ✅ Cuando el stock baje de 5 unidades, Odoo generará automáticamente una solicitud de compra al proveedor.

---

## 🏭 PASO 4 — Asignar proveedor al producto

**Dónde ir:** Inventario → Productos → Calificación → Pestaña "Compras"

1. Clic en la pestaña **"Compras"**
2. Clic en **"Agregar una línea"**
3. Selecciona el proveedor: **TechDistrib GT**
4. Precio unitario: **50**
5. Plazo de entrega: **7**
6. **Guarda**

> ✅ El producto queda vinculado al proveedor para el reordenamiento automático.

---

## 🛒 PASO 5 — Crear la venta (10 unidades de Calificación)

**Dónde ir:** Ventas → Órdenes → Cotizaciones → Nuevo

1. En **"Cliente"** selecciona: **Andrea Sofía Ramírez Fuentes**
2. Clic en **"Agregar un producto"**
3. Selecciona **Calificación**
4. En **Cantidad** escribe **10**
5. Verifica que el precio unitario sea **100**
6. Clic en **"Confirmar"**

> ✅ La cotización cambia a estado **"Pedido de venta"**

---

## 🧾 PASO 6 — Crear la factura

**Dónde ir:** Dentro del pedido de venta confirmado

1. Arriba verás el botón **"Facturar"** — haz clic
2. Aparece una ventana que dice **"Crear facturas"**
3. Clic en **"Crear factura"**
4. Se abre la factura con los **10 productos Calificación**
5. Verifica que el total sea correcto: **Q 1,000.00**

> ⚠️ Si no aparece el botón "Facturar", verifica que el pedido esté en estado "Pedido de venta" y no en borrador.

---

## ✅ PASO 7 — Validar la factura

**Dónde ir:** Dentro de la factura recién creada

1. Verás el botón **"Confirmar"** arriba — haz clic
2. La factura cambia de estado **"Borrador"** → **"Publicado"**

> ✅ La factura está validada cuando dice **"Publicado"** en verde. ¡Ejercicio completado!

---

## ⚠️ Tips importantes para el examen

- **Si no aparece "Facturar"** → asegúrate de haber confirmado el pedido primero
- **Si pide "Política de facturación"** → selecciona "Cantidades ordenadas"
- **La factura debe quedar en "Publicado"** → no en borrador, ese es el paso final
- **No olvides guardar** después de cada paso importante
- **El stock baja automáticamente** cuando confirmas el pedido de venta

---

## 📍 Referencia rápida de rutas

| Paso | Ruta en Odoo |
|---|---|
| Crear producto | Inventario → Productos → Productos → Nuevo |
| Agregar stock | Dentro del producto → Actualizar cantidad |
| Regla reordenamiento | Inventario → Operaciones → Reabastecimiento → Nuevo |
| Asignar proveedor | Producto → Pestaña Compras → Agregar línea |
| Crear venta | Ventas → Órdenes → Cotizaciones → Nuevo |
| Facturar | Dentro del pedido confirmado → Botón Facturar |
| Validar | Dentro de la factura → Botón Confirmar |
