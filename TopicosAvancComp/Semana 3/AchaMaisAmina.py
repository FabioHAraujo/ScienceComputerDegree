ent = open("7x7n.pdb", "r")
sai = open("7x7nnn.pdb", "w")

for i in ent:
    if i[0:4] == "ATOM":
        if i[17:20] == "PHE":
            if i[21:22] == "A":
                sai.write(i)
ent.close()
sai.close()
