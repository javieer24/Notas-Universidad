import graphviz

# Función para crear un autómata simple de una expresión
def crear_afn_simple(expresion, nombre):
    afn = graphviz.Digraph(nombre, format='png')
    afn.attr(rankdir='LR')

    # Estado inicial y final
    afn.node('q0', shape='circle', style='filled', fillcolor='lightgray')
    afn.node('qf', shape='doublecircle', style='filled', fillcolor='lightgray')

    # Transición con la expresión
    afn.edge('q0', 'qf', label=expresion)

    return afn

# Creación de los AFN para cada expresión
afn_a = crear_afn_simple('(a?bc+|d*ca?)+b?c*a', 'AFN_A')
afn_b = crear_afn_simple('a?bc+|d*ca?|b?c*a', 'AFN_B')
afn_c = crear_afn_simple('a(b|c|ε)de+f|ε?hi', 'AFN_C')
afn_d = crear_afn_simple('m(n|o)+pq|rs+t', 'AFN_D')
afn_e = crear_afn_simple('(x|y|z?w+u|v?)xy', 'AFN_E')

# Renderizar y guardar las imágenes
afn_a.render('/mnt/data/AFN_A')
afn_b.render('/mnt/data/AFN_B')
afn_c.render('/mnt/data/AFN_C')
afn_d.render('/mnt/data/AFN_D')
afn_e.render('/mnt/data/AFN_E')

# Devolver las imágenes generadas
['/mnt/data/AFN_A.png', '/mnt/data/AFN_B.png', '/mnt/data/AFN_C.png', '/mnt/data/AFN_D.png', '/mnt/data/AFN_E.png']
