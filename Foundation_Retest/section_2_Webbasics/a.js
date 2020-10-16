//Function validateForm
//Description This function validates all the fields of the form by invoking them.
//			It checks for:
//			all the fields should be completed
//			Validate name
//			validate email id
//			validate phone number
//Author : Swapnil Kadam
			

function validateForm()
{
	if(empty_check())// If all fields completed then proceed
	{
		// Checks for all the validation
		// The methods are invoked and checked in if for the valid data
		if( (valid_title()) && (valid_name()) && (valid_last_name()) && (valid_phone()) && (valid_email()) && (valid_state()) && (valid_city()))
		{
			alert("All data entered correctly");
			return true;
		}
		else
			return false;
	}
	else
		return false;

}



//Function empty_check
//Description Alerts the user if any field is blank and returns false else it
//returns true.
//Return value boolean

	function empty_check()
	{
		// Retrive all the form elements
		var form_all=document.forms["cust_form"];
		// Iterate through all the elements.
		for (index=0; index<form_all.length;index++)// form_all.length gives total
													// number of elements
		{
			// Checks for a blank
			if(form_all.elements[index].value=="")
			{
				// If field empty prompt the user
				alert("All fields are mandatory");
				// returns false to indicate validation failed
				return false;
			}
			
		}
		// If all fields are filled returns true indicating validation success
		return true;
	}

//Function valid_title
//Description Alerts the user if title is not selected
//Return value boolean

	function valid_title()
	{
		// Retrieves the title value from the text field
		var title_val=document.getElementById("title_cust").value;
		// alert(title_val);
		if(title_val==-1)
		{
			alert("Select a title");
			return false;
		}
		else 
			return true;
			
	}	


//Function valid_name
//Description Alerts the user if customer first name contains numbers
//Return value boolean

	function valid_name()
	{
		// Retrieves the customer value from the text field
		var name=cust_form.cust_name.value;
		// Check for the character validation
		var exp=/\D+$/;
		var reg_name=new RegExp(exp);
		if(!(reg_name.test(name)))
		{
			alert("Name must not contain any numbers");
			return false;
		}
		else
			// returns true to indicate validation success
			return true;
		
	}


//Function valid_name
//Description Alerts the user if customer last name contains numbers
//Return value boolean

	function valid_last_name()
	{
		// Retrieves the customer value from the text field
		var name=cust_form.cust_surname.value;
		// Check for the character validation
		var exp=/\D+$/;
		var reg_name=new RegExp(exp);
		if(!(reg_name.test(name)))
		{
			alert("Last Name must not contain any numbers");
			return false;
		}
		else
			// returns true to indicate validation success
			return true;
		
	}



// Function valid_phone
// Description Alerts the user if Phone number is invalid and is not of 10
// digits
// Return value boolean

	function valid_phone()
	{
		// Retrieves the customer value from the text field
		var mobile=cust_form.mobile_number.value;
		// Check for the character validation
		var exp=/\d{10}/;
		var reg_name=new RegExp(exp);
		if(!(reg_name.test(mobile)))
		{
			alert("Mobile Number must contain 10 digits");
			return false;
		}
		else
			// returns true to indicate validation success
			return true;
		
	}


// Function valid_email
// Description Alerts the user if email id is invalid
// Return value boolean

	function valid_email()
	{
		// Retrieves the customer value from the text field
		var email=cust_form.cust_email.value;
		// Check for the character validation
		var exp=/\D+@\D+\.\D+/;;
		var reg_name=new RegExp(exp);
		if(!(reg_name.test(email)))
		{
			alert("Please enter correct e-mail id");
			return false;
		}
		else
			// returns true to indicate validation success
			return true;
		
	}


//Function valid_state
//Description Alerts the user if title is not selected
//Return value boolean
	
	function valid_state()
	{
		// Retrieves the title value from the text field
		var title_val=document.getElementById("cust_stat").value;
		// alert(title_val);
		if(title_val==-1)
		{
			alert("Select a State");
			return false;
		}
		else 
			
			return true;
			
	}
//Function valid_city
//Description Alerts the user if title is not selected
//Return value boolean

	function valid_city()
	{
		// Retrieves the title value from the text field
		var title_val=document.getElementById("cust_city").value;
		// alert(title_val);
		if(title_val==-1)
		{
			alert("Select a City");
			return false;
		}
		else 
			
			return true;
			
	}