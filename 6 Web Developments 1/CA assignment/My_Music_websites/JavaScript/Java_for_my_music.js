function validate()
{ 
	//This is to get the user to input the first name into the form

	if (document.regForm.First_name.value == "")
	{
		document.getElementById("firstName").innerHTML = "First name can't be blank";
	 	
	 	return false;
	}
	
	//This is to make sure the user puts in their surname

	if (document.regForm.surname.value == "")
	{
	 document.getElementById("SurName").innerHTML = "Surname can't be blank";
		
		return false;
	}

	//This is to check to make sure the age is not blank


	if (document.regForm.year_knowledge.value == "")
	{
	 document.getElementById("Year_knowledge").innerHTML = "Year can't be blank";
		
		return false;
	}

	//This is to make the text entered is a number

	var year = document.regForm.year_knowledge.value;

	year = Number(year);

	if (isNaN(year))
	{
		document.getElementById("Year_knowledge").innerHTML = "Year can't be in this format";

		return false;
	}

	//This is to check that email is not blank

	if (document.regForm.email.value == "")
	{
	 document.getElementById("E-MAIL").innerHTML = "Email can't be blank";
		
		return false;
	}

	//The following is to validate the Email

	var email_java = document.regForm.email.value;

if (validateEmail(email_java) == false)
{
	//alert("Email is not in the right format");

	document.getElementById("E-MAIL").innerHTML = "Email can't be in this format";

	return false;
}

	

	function	validateEmail(email)
	{	
		var	re	=	/^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;	
						
		return	re.test(email);	

	}	

	return true;
}


