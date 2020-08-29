//alert("I'm JavaScript!");
let login = prompt('Who is there?', '');

let password = '';

if(login == "Admin")
{
	password = prompt('Insert password', '');
	if(password == "I'm the boss"){
		alert("Hello!");
	}
	else {
		alert("Wrong password");
	}
}
else {alert("I don't know you");}

//alert(`Hi , ${name}`);
//let isBoss = confirm("Are you the boss here?");
//alert(isBoss);