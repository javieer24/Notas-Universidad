#include <iostream>
#include <fstream>

void generateCircuitDotFile() {
    std::ofstream dotFile("mealy_circuit_diagram.dot");

    dotFile << "digraph MealyCircuit {\n";
    dotFile << "    rankdir=LR;\n";
    dotFile << "    size=\"10,7\";\n";
    dotFile << "    node [shape = rectangle];\n";

    // Flip-Flops
    dotFile << "    Q2 [label=\"Flip-Flop Q2\"];\n";
    dotFile << "    Q1 [label=\"Flip-Flop Q1\"];\n";
    dotFile << "    Q0 [label=\"Flip-Flop Q0\"];\n";

    // Inputs
    dotFile << "    Input [shape=circle, label=\"Input\"];\n";
    
    // Logic Gates
    dotFile << "    AND0 [label=\"AND\"];\n";
    dotFile << "    AND1 [label=\"AND\"];\n";
    dotFile << "    AND2 [label=\"AND\"];\n";
    dotFile << "    OR0 [label=\"OR\"];\n";
    dotFile << "    OR1 [label=\"OR\"];\n";
    dotFile << "    OR2 [label=\"OR\"];\n";
    dotFile << "    NOT0 [label=\"NOT\"];\n";
    dotFile << "    NOT1 [label=\"NOT\"];\n";
    dotFile << "    NOT2 [label=\"NOT\"];\n";
    dotFile << "    NOT3 [label=\"NOT\"];\n";

    // Connections for state Q2'
    dotFile << "    Q2 -> NOT0;\n";
    dotFile << "    NOT0 -> AND0;\n";
    dotFile << "    Q1 -> AND0;\n";
    dotFile << "    Q0 -> NOT1;\n";
    dotFile << "    NOT1 -> AND0;\n";
    dotFile << "    Input -> AND0;\n";
    dotFile << "    AND0 -> OR0;\n";
    dotFile << "    Q2 -> AND1;\n";
    dotFile << "    Q1 -> NOT2;\n";
    dotFile << "    NOT2 -> AND1;\n";
    dotFile << "    Q0 -> AND1;\n";
    dotFile << "    Input -> NOT3;\n";
    dotFile << "    NOT3 -> AND1;\n";
    dotFile << "    AND1 -> OR0;\n";
    dotFile << "    OR0 -> Q2;\n";
    
    // Connections for state Q1'
    dotFile << "    Q2 -> NOT0;\n";
    dotFile << "    NOT0 -> AND0;\n";
    dotFile << "    Q1 -> AND0;\n";
    dotFile << "    Q0 -> NOT1;\n";
    dotFile << "    NOT1 -> AND0;\n";
    dotFile << "    Input -> AND0;\n";
    dotFile << "    AND0 -> OR0;\n";
    dotFile << "    Q2 -> AND1;\n";
    dotFile << "    Q1 -> NOT2;\n";
    dotFile << "    NOT2 -> AND1;\n";
    dotFile << "    Q0 -> AND1;\n";
    dotFile << "    Input -> NOT3;\n";
    dotFile << "    NOT3 -> AND1;\n";
    dotFile << "    AND1 -> OR0;\n";
    dotFile << "    OR0 -> Q2;\n";
    
    // Connections for state Q0'
    dotFile << "    Q2 -> NOT0;\n";
    dotFile << "    NOT0 -> AND0;\n";
    dotFile << "    Q1 -> AND0;\n";
    dotFile << "    Q0 -> NOT1;\n";
    dot
