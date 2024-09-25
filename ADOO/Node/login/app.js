const express = require("express");
const mysql = require("mysql");
const passport = require("passport");
const LocalStrategy = require("passport-local").Strategy;
const bcrypt = require("bcryptjs");
const session = require("express-session");
const { log } = require("console");

const app = express();

app.use(express.urlencoded({ extended: false }));
app.use(
  session({
    secret: "secret",
    resave: false,
    saveUninitialized: false,
  })
);

const db = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "Fr19931993",
  database: "logindb",
});

db.connect((err) => {
  if (err) {
    console.error("Error al conectar a la base de datos", err);
    return;
  }
  console.log("Conectado a la base de datos");
});

app.use(passport.initialize());
app.use(passport.session());

passport.use(
  new LocalStrategy((username, password, done) => {
    db.query(
      "Select * from users where username = ?",
      [username],
      (err, results) => {
        if (err) {
          console.log("Error en la consulta de la base de datos", err);
          return done(err);
        }

        console.log("Resultados de la consulta", results);

        if (results.length === 0) {
          return done(null, false, { message: "No existe ese usuario" });
        }

        const user = results[0];

        bcrypt.compare(password, user.password, (err, isMatch) => {
          if (err) {
            console.log("Error en la comparación de contraseñas", err);
            return done(err);
          }
          if (isMatch) {
            console.log("Usuario encontrado", user);
            return done(null, user);
          } else {
            console.log("Contraseña incorrecta");
            return done(null, false, { message: "Contraseña incorrecta" });
          }
        });
      }
    );
  })
);

passport.serializeUser((user, done) => {
  done(null, user.id);
});

passport.deserializeUser((id, done) => {
  db.query("Select * from users where id = ?", [id], (err, results) => {
    done(err, results[0]);
  });
});

app.set("view engine", "ejs");

app.get("/", (req, res) => {
  res.render("index");
});

app.listen(3000, () => {
  console.log("Server corriendo en el puerto 3000");
});

app.get("/login", (req, res) => {
  res.render("login");
});

app.post(
  "/login",
  passport.authenticate("local", {
    successRedirect: "/dashboard",
    failureRedirect: "/login",
    failureFlash: false,
  })
);

app.get("/logout", (req, res) => {
  req.logout((err) => {
    if (err) {
      return next(err);
    }
    res.redirect("/login");
  });
});

app.get("/dashboard", (req, res) => {
  if (req.isAuthenticated()) {
    res.render("dashboard", { user: req.user });
  } else {
    res.redirect("/login");
  }
});

app.get("/register", (req, res) => {
  res.render("register");
});

app.post("/register", async (req, res) => {
  const { username, password } = req.body;

  const hashedPassword = await bcrypt.hash(password, 10);

  const sql = `INSERT INTO users (username, password) VALUES (?, ?)`;
  db.query(sql, [username, hashedPassword], (err, result) => {
    if (err) throw err;
    res.redirect("/login");
  });
});
