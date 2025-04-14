function envoimail(event) {
    event.preventDefault(); // Empêche le rechargement de la page

    // Récupérer les valeurs des champs du formulaire
    const prenom = document.getElementById('prenom').value;
    const nom = document.getElementById('nom').value;
    const email = document.getElementById('email').value;
    const message = document.getElementById('message').value;

    // Afficher les données dans la console
    console.log(`Prénom: ${prenom}`);
    console.log(`Nom: ${nom}`);
    console.log(`Email: ${email}`);
    console.log(`Message: ${message}`);

    // Exemple : afficher une alerte pour confirmer la récupération des données
    alert("Les données du formulaire ont été traitées avec succès !");
}
