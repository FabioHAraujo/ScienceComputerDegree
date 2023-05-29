ent = open("7x7n.pdb", "r")
sai = open("7x7nn.pdb", "w")

for i in ent:
    if i[0:4] == "ATOM":
        if i[13:15] == "CA":
            sai.write(i)
ent.close()
sai.close()