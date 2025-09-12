alleles = ['A', 'B', 'O']
import random
import sys

def create_family(generations):
    if generations <= 0:
        return None
    elif generations == 1:
        return (None,None, random.choice(alleles),  random.choice(alleles))
    else:
        parent1 = create_family(generations - 1)
        parent2 = create_family(generations - 1)
        child_allele1 = random.choice([parent1[2], parent1[3]])
        child_allele2 = random.choice([parent2[2], parent2[3]])
        return (parent1, parent2, child_allele1,child_allele2)


def print_family(family, generation=0):
    if family is None:
        return
    indent = ' ' * (generation * 4)
    if generation == 0:
        print(f"{indent}Child (Generation {generation}): {family[-1]}{family[-2]}")
    elif generation == 1:
        print(f"{indent}Parent (Generation {generation}): {family[-1]}{family[-2]}")
    else:
        prefix = "Great-" * (generation - 1) if generation > 2 else ""
        print(f"{indent}{prefix}Grandparent (Generation {generation}): {family[-1]}{family[-2]}")
       
    print_family(family[0], generation + 1)
    print_family(family[1], generation + 1)

generations = input("Enter number of generations: ")
try:
    generations = int(generations)
except ValueError:
    print("Please enter a valid integer.")
    sys.exit(1)



family = create_family(generations)
print_family(family,0)

