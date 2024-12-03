
use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::cmp::Ordering;


fn main() -> io::Result<()>
{
	let mut total_distance = 0;



	// let path = Path::new("input.txt");
	// let file = File::open(&path)?;

	let file = File::open("input.txt")?;

	let mut left = Vec::new();
	let mut right = Vec::new();

	for line in io::BufReader::new(file).lines()
	{
		let line = line?; // Si une erreur se produit, elle sera renvoyée
		let parts: Vec<i32> = line
			.split_whitespace() // Sépare la ligne en mots
			.filter_map(|s| s.parse().ok()) // Convertit chaque mot en un entier
			.collect(); // Collecte les entiers dans un vecteur

		if parts.len() == 2
		{
			left.push(parts[0]);
			right.push(parts[1]);
		}
	}

	left.sort();
	right.sort();

	println!("Total distance: {}", total_distance);

	Ok(())
}


/*
Variable declaration:

let x =5; //can't modify
let mut y=10; //can modify

#GESTION DES ERREURS

enum Result<T, E> {
    Ok(T),
    Err(E),
}

Ok(T) : contient la valeur de type T lorsque l'opération réussit.
Err(E) : contient une erreur de type E lorsque l'opération échoue.

io::Result<()> utilise specialement pour les E/S
io::Result<()> est un type de retour qui indique :

    Ok(()) si l'opération réussit, et donc il n'y a pas de valeur supplémentaire à retourner (c'est juste un "succès").
    Err(io::Error) si une erreur se produit lors d'une opération d'entrée/sortie.

// Si `line` est Ok(String), la valeur est assignée à `line`

	*/
