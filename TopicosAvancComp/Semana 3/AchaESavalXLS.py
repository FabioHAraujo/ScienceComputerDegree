ent = open("7x7n.pdb", "r")
sai = open("7x7nnn.csv", "w")

for i in ent:
    if i[0:4] == "ATOM":
        if i[17:20] == "PHE":
            if i[21:22] == "A":
                linha = i.split()
                t = linha[0] + "; " + linha[1] + "; " + linha[2] + "; " + linha[3] + "\n"
                sai.write(t)
ent.close()
sai.close()
