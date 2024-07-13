import json
import estilo as es
import tkinter as messagebox

class JsonFile:
    
    def create_ErroresJSON(errores):
        data = {
            "errores": []
        }

        for error in errores:
            data["errores"].append({
                "lexema": error[0],
                "tipo": error[1],
                "fila": error[2],
                "columna": error[3]
            })

        json.dump(data, open("jsons/Errores_202100081", 'w'))
        
    def create_ResultadosJSON(texto, title_operaciones, operaciones, expre):
        
        def create_json_object(title, description, operaciones, expre):
            data = {
                "title": title,
                "description": description,
                "operaciones": []
            }

            for num, op in zip(operaciones, expre):
                data["operaciones"].append({
                    "numero": num,
                    "expresion": op
                })

            return data

        def write_json_file(data, filename):
            with open(filename, "w") as f:
                json.dump(data, f)

        def show_success_message():
            messagebox.showinfo("Analizador", "Archivo Analizado correctamente")

        data = create_json_object(title_operaciones, texto, operaciones, expre)
        write_json_file(data, "Resultasdos.202100081.json")
        show_success_message()

        return data



