


jQuery(document).ready(function(){

//orientation changes for slider

window.addEventListener('orientationchange', function () {
   window.location.reload();
  });
  

    //Detection for external links
    hostname = new RegExp(location.host);
    // Act on each link
    jQuery('a[href]').each(function(){
        // Store current link's url
        var url = jQuery(this).prop("href");

        // Test if current host (domain) is in it
        if(!hostname.test(url)){
            // a link that does not contain the current host i.e external link
            jQuery(this).addClass('external-link').append("<span class='ext'></span>");
            jQuery(this).attr('target', '_blank');
        }
    });
	
	
	jQuery('#views-exposed-form-aktuelles-page select').select2({
        minimumResultsForSearch: Infinity
	}); 
	
	jQuery("#views-exposed-form-projekt-map-project-map select").select2({
		
		minimumResultsForSearch: Infinity
	});
	
	
	jQuery("input:radio").each(function(){
  if(jQuery(this).is(':checked'))
  {
	jQuery(this).parent("label").css('border-bottom', '2px solid #e74712');
  }
}); 

// scrollbar

jQuery('.page-aktuelles select').select2().on("select2:open", function(){
 jQuery('.page-aktuelles .select2-results').addClass("simplebar");
 jQuery('.page-aktuelles .select2-results').simplebar();
});

jQuery('.page-projekt-map select').select2().on("select2:open", function(){
 jQuery('.page-projekt-map .select2-results').addClass("simplebar");
 jQuery('.page-projekt-map .select2-results').simplebar();
});


jQuery(window).click(function(event){
		jQuery(".views-exposed-widget").removeClass("selColor");
});

jQuery(".select2").on("click", function(event){
	event.stopPropagation();
	jQuery(this).parents(".views-exposed-widget").addClass("selColor").siblings().removeClass("selColor");
	if(!jQuery(this).next().is(".select2-container")){
		jQuery(this).parent().append(jQuery(".select2-dropdown").parent());
		jQuery(this).next().attr("style","top:29px !important;left:0 !important;");		
	}	
});
	
//search
	
    //open popup
    jQuery('.search-icon').on('click', function(event){
        event.preventDefault();
		jQuery(this).addClass('active');
        jQuery('.block-ipwa-search').addClass('is-visible');
    });
    
    // close popup 
    jQuery(".cross-link").on('click',function(){
		jQuery(".search-icon").removeClass('active');
		jQuery(".block-ipwa-search").removeClass('is-visible');
		
		
	});
	
	// Copyright for video block single view
	
	if(jQuery(document).find(".field-name-field-videounterschrift").length > 0){
		var copyText1 = jQuery(".field-name-field-videoquelle .field-label").text(), 
		copyText2 = jQuery(".field-name-field-videoquelle .field-items .field-item").text(), 
		copyText = copyText1 + copyText2;
		jQuery(".field-name-field-videounterschrift .field-item").append("<span class='copyright'> " + copyText + "</span>");
		jQuery(".field-name-field-videoquelle").hide();
	}


	


	// header-mobile-menu
	
	if(jQuery(window).innerWidth() < 1025){
	
	jQuery(".navbar-toggle").click(function(){
		jQuery(this).toggleClass("active");
		jQuery(".navbar-collapse").toggle();	
			});
		
		
		jQuery(".navbar-nav").insertAfter(".region-navigation");
jQuery('.tb-megamenu-submenu.dropdown-menu').attr('style','display:none !important');		
		 jQuery("ul.tb-megamenu-nav li a").click(function(){	
			 jQuery(this).next(".tb-megamenu-submenu").attr('style','display:block !important');
			jQuery(this).parent().siblings().find(".tb-megamenu-submenu").attr('style','display:none !important');
			jQuery(this).parent().siblings().removeClass("open");
		}); 
	};

    jQuery(function() {
        var pop_up_id;
        jQuery('div.pop-up').hide();
        jQuery('a.trigger').hover(function() {
            pop_up_id = this.id;
            pop_up_id = pop_up_id.substring(8);
            jQuery('div#pop-up-' + pop_up_id).show();
        }, function() {
            pop_up_id = this.id;
            pop_up_id = pop_up_id.substring(8);
            jQuery('div#pop-up-' + pop_up_id).hide();
        });
    });
	
	// Calendar view work
	
	jQuery(".date-display-recurring").parent().addClass("recurring");
	jQuery(".date-display-single").parent().addClass("single");
	
	// Mouse over functionality
	
	jQuery(".date-box td").on("mouseover", function(){
		var positionTD = jQuery(this).index();
		jQuery(this).addClass("greyHover");
		jQuery(this).parent().next(".single-day").find("td:eq(" +positionTD+ ")").addClass("greyHover")
	}).on("mouseout", function(){
		jQuery("table tr td").removeClass("greyHover");
	});
	
	
	jQuery(".single-day td").on("mouseover", function(){
		var positionTD = jQuery(this).index();
		jQuery(this).addClass("greyHover");
		jQuery(this).parent().prev(".date-box").find("td:eq(" +positionTD+ ")").addClass("greyHover")
	}).on("mouseout", function(){
		jQuery("table tr td").removeClass("greyHover");
	});
	
	
	// Click functionality
	
	jQuery(".date-box td").on("click", function(){
		var positionTD = jQuery(this).index();
		jQuery(this).addClass("redHover");
		jQuery(this).siblings().removeClass("redHover");
		jQuery(this).parent().siblings().find("td").removeClass("redHover");
		jQuery(this).parent().next(".single-day").find("td:eq(" +positionTD+ ")").addClass("redHover")
	});/*.on("mouseout", function(){
		if(!jQuery(this).parent().siblings().find("td:eq(" +positionTD+ ")").is(".redHover")){
			jQuery("table tr td").removeClass("redHover");
		}
	}); */
	
	jQuery(".single-day td").on("click", function(){
		var positionTD = jQuery(this).index();
		jQuery(this).addClass("redHover");
		jQuery(this).siblings().removeClass("redHover");
		jQuery(this).parent().siblings().find("td").removeClass("redHover");
		jQuery(this).parent().prev(".date-box").find("td:eq(" +positionTD+ ")").addClass("redHover")
	});/*.on("mouseout", function(){
		if(!jQuery(this).parent().siblings().find("td:eq(" +positionTD+ ")").is(".redHover")){
			jQuery("table tr td").removeClass("redHover");
		}
	}); */
	
	/* jQuery(window).click(function(event){
		if(!jQuery(event.target).is(".redHover")){
			jQuery("table tr td").removeClass("redHover");
		}
	}); */
	
	
	// Calendar view
	
	/* jQuery(".page-calendar .view-content .calendar-calendar .inner .item .calendar span a").on("focus", function(){
		jQuery(this).mouseover();
		// jQuery(this).hover();
		jQuery(this).next(".views-row").attr("style", "display:block !important;");
		jQuery(this).parents("td, tr").siblings().find(".trigger").mouseout();
		jQuery(this).parents("td, tr").siblings().find(".trigger").next(".views-row").removeAttr("style");
	}); */
	



	
	// Calendar tool-tip
	
	jQuery(".single-day td .trigger").mouseover(function(){
		var toolId = jQuery(this).attr("id"), toolTipBox;
		jQuery(".view-event-on-calendar .view-content .views-row").each(function(index, element){
			var tipId = jQuery(element).find(".field-content .row-container").attr("id");
			if(toolId == tipId){
				//jQuery(this).parent().append(jQuery(element));
				toolTipBox = jQuery(element).clone();
			}
		});
		if(!jQuery(this).next().is(".views-row")){
			jQuery(this).parent().append(toolTipBox);
		}
		
		// Sensible mouseover tool tip
		if(jQuery(this).parents("td").is(":last-child, :nth-last-child(2)")){
			jQuery(this).next(".views-row").addClass("rightBorder");
		}
		// jQuery(this).next().show();
	});
	
	// Click on trigger
	
	jQuery(".single-day td .trigger").click(function(event){
		event.preventDefault();
	});
	
	// Structural changes
	
	jQuery(".page-calendar .calendar-link").insertAfter(jQuery("#edit-term-node-tid-depth-wrapper"));
	var monthText = jQuery(".page-calendar .date-views-pager h3").text();
	jQuery(".page-calendar .date-views-pager .pagination .prev").after("<li class='monthText'>" +monthText+ "</li>");
	jQuery(".page-calendar .date-views-pager").insertAfter(jQuery(".page-calendar .view-filters .calendar-link"));
	jQuery(".date-views-pager, .views-widget-sort-by").wrapAll("<div>");
	

	 jQuery(".page-taxonomy-term .view-alles-zum-thema .view-sub-wrapper .view-filters .views-exposed-form .views-exposed-widgets .views-widget-sort-by .bef-select-as-links .form-type-bef-link:first-child a").addClass("active");

	jQuery("#page_print").click(function(){
		window.print();
	});
	
	if(jQuery(window).innerWidth() <= 1024){
		jQuery(".nrw-eu-logo a").insertAfter(jQuery(".navbar-header .navbar-btn"));
	
	
		jQuery("header .container .navbar-collapse .region-navigation .tb-megamenu ul.tb-megamenu-nav li > a").click(function(){
			 jQuery('html, body').animate({
				scrollTop: jQuery(this).offset().top
			  },600); 
			
		});
		
	}
	
	jQuery(".block-ipwa-newsletter .form-submit").insertAfter(".block-ipwa-newsletter .form-item-newsletter .form-control");
	
	// Add to calendar link
	
	jQuery(".addtocalendar").appendTo(jQuery(".group-left-top-wrapper .group-middle-wrapper"));
	
	//footer icons//
	
	jQuery(".footer .footer_blocks").insertAfter(".footer .region-footer .block-menu");
	
	//termine view
	jQuery(".view-termin .view-filters .views-exposed-form .views-exposed-widgets .views-widget-sort-by").appendTo(".view-termin .attachment-before");
	
	
	// Share link tab indexing
	
	jQuery("#block-addthis-addthis-block a").attr("href", "");
	
	// Label tabs
	
	jQuery(".form-type-radio label, .search-icon").attr("tabindex", "0");
	
	// On enter key press
	jQuery(".form-type-radio label, .search-icon").keypress(function (e) {
		 var key = e.which;
		 if(key == 13)  // the enter key code
		  {
			jQuery(this).click();
			// Search input
			jQuery("#edit-search-text").focus();
			return false;  
		  }
	});
	
	// Tab accessibility
	
	jQuery(".tb-megamenu .nav > li > a").on('focus', function(){
		jQuery(this).mouseover();
		jQuery(this).parent().siblings().find("a").mouseout();
	});
	
	// Tabbed drop downs list view
	
	jQuery(".select2-selection--single").on('focus', function(){
		jQuery(this).parents(".views-exposed-widget").addClass("focused");
		jQuery(this).parents(".views-exposed-widget").siblings().removeClass("focused");
	});
	
	jQuery(".select2-selection--single").on('blur', function(){
		if(jQuery(this).parents(".views-exposed-widget").is(":last-child")){
			jQuery(this).parents(".views-exposed-widget").removeClass("focused");
		}
	});
	
	// Outline for blue boxes
	
	jQuery(".project-blue, .front .view-termin .view-sub-wrapper .row-container").parent().on("focus", function(){
		jQuery(this).attr("style", "outline:2px dotted #e74712 !important;")
		// jQuery(this).parent(".views-row").siblings().find("a").attr("style", "outline:0;")
	});
	
	jQuery(".project-blue, .front .view-termin .view-sub-wrapper .row-container").parent().on("blur", function(){
		jQuery(this).attr("style", "outline:0;")
		/* if(jQuery(this).parent(".views-row").is(":last-child")){
			jQuery(this).attr("style", "outline:0;");
		} */
	});
	
	// Newsletter validations
	
	jQuery("#ipwa-newsletter-block-form #edit-submit--2").click(function(){
		var newsEmail = /^[A-Z0-9._%+-]+@([A-Z0-9-]+\.)+[A-Z]{2,4}$/i, newsValue = jQuery("#edit-newsletter").val();
		jQuery(this).parent().find(".error").remove();
		if(newsValue == ""){
			jQuery(this).parent().append("<div class='error'>Eine E-mail Adresse ist erforderlich</div>");
			return false;
		}
		else if(!newsEmail.test(newsValue)){
			jQuery(this).parent().append("<div class='error'>Verwenden Sie eine gültige E-Mail Adresse</div>");
			return false;
		}
		else{
			return true;
		}
	});
	
	// Calendar tool tip appearacnce work for responsive
	if(jQuery(window).innerWidth() <= 768){
		jQuery(".trigger").click(function(){
				jQuery(this).mouseover();
				jQuery(this).next().show();
				jQuery(this).parents(".item, td, tr").siblings().find(".trigger + .views-row").hide();
				jQuery('.calendar-calendar').animate({
					scrollLeft: 0
				}, 0);
				if(jQuery(this).parents("tr").is(":last-child, :nth-last-child(2)")){
					jQuery('.calendar-calendar').animate({
						scrollTop: jQuery(this).offset().top - 200,
						scrollLeft: jQuery(this).offset().left - 150
					}, 500);	
				}
				else{
					jQuery('html, body').animate({
						scrollTop: jQuery(this).offset().top - 200,
					}, 500);
					jQuery('.calendar-calendar').animate({
						scrollLeft: jQuery(this).offset().left - 150
					}, 500);	
				}
		});
	}
	
	//page-projekt-map
	
	if(jQuery(".view-projekt-map").length > 0){
	jQuery(document.body).addClass("page-projekt-map");
} 
	
	
	
});


