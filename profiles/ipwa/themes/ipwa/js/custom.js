jQuery(document).ready(function(){

    //Detection for external links
    hostname = new RegExp(location.host);
    // Act on each link
    jQuery('a[href]').each(function(){
        // Store current link's url
        var url = jQuery(this).prop("href");

        // Test if current host (domain) is in it
        if(!hostname.test(url)){
            // a link that does not contain the current host i.e external link
            jQuery(this).addClass('external-link');
            jQuery(this).attr('target', '_blank');
        }
    });
});