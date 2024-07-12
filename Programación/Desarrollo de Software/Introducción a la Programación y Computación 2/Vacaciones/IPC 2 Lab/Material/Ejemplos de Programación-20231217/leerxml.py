import xml.etree.ElementTree as ET

try:
    xml_file = open('plants.xml')
     # print(xml_file.read())
    if xml_file.readable():
        xml_data = ET.fromstring(xml_file.read())
        lst_plants = xml_data.findall('PLANT')
        for plant in lst_plants:
            print(f"Nombre : {plant.find('COMMON').text}")
            print(f"Botanica : {plant.find('BOTANICAL').text}")
            print(f"Zona : {plant.find('ZONE').text}")
            print(f"LIGHT : {plant.find('LIGHT').text}")
            print(f"PRICE : {plant.find('PRICE').text}")
            print(f"AVAILABILITY : {plant.find('AVAILABILITY').text}")
            print("------------------------------------")
        
        
    else:
       print(False)

except Exception as err:
    print("Error:", err)
    
finally:
    xml_file.close()