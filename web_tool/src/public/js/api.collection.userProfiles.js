var app = angular.module("col_userProfiles", [])
var _URL_API_USERPROFILES = require('./api.collection')._URL_API_USERPROFILES;
app.controller("col_userProfilesClassCtrl", function( $scope, $http ) {   
    
    $scope.showDatas = function()
     {        
        
        $http.get(_URL_API_USERPROFILES).then(function(response)
        {
            if(response.data.col_userProfiles) 
            {
                $scope.col_userProfiles = response.data.col_userProfiles; 
            }
        });        

    };
    $scope.showDatas();    
    
});
