$(document).ready(function() {
  $('#notice').fadeOut(5000)

  var colours = ['#001F3F', '#0074D9', '#7FDBFF', '#39CCCC', '#3D9970',
                    '#2ECC40', '#01FF70', '#FFDC00', '#FF851B', '#FF4136',
                    '#85144B', '#F012BE', '#B10DC9']


  if ($('.center') !== []) {
    var currentColour = 0;
    function switchColour() {    
      if (currentColour >= colours.length) currentColour = 0;

      $('html, body').css('background-color', colours[currentColour++])

      setTimeout(switchColour, 1100);
    }

    switchColour();
  }
})