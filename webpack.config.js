const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const outputDir = path.join(__dirname, "build/");

const isProd = process.env.NODE_ENV === "production";

module.exports = {
  entry: "./src/WebpackEntry.bs.js",
  mode: isProd ? "production" : "development",
  output: {
    path: outputDir,
    filename: "app.js",
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: "src/index.html",
      inject: false,
    }),
  ],
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 8080,
    historyApiFallback: true,
  },
};
