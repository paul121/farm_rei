(function () {
  farmOS.map.behaviors.active_rei = {
    attach: function (instance) {

      // Add the active REI GeoJSON layer.
      var opts = {
        title: "Restricted areas (active REI)",
        url: '/farm/areas/active-rei/geojson',
        color: 'red',
      }
      instance.addLayer('geojson', opts);
    }
  };
}())
